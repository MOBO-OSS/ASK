#ifndef __RINGMEMBUFF_H__
#define __RINGMEMBUFF_H__

#include "TypesRedefine.hpp"
//#include "stdlib.h"
#include <string>

#define MAX_ASK_FOR_CAP       (1 << 16)  // 64K

struct BufferInfo{
    BufferInfo(unsigned int r = 0, unsigned int w = 0, unsigned int c = 0)
            : read(r)
            , write(w)
            , capacity(c)
            , mask(c - 1)
    {
    }
    unsigned int read;  // read index in buffer
    unsigned int write;  // write index in buffer
    unsigned int capacity;  // capacity of the buffer
    unsigned int mask;  // mask of the capacity
};

template <typename T>
class RingMemPool
{
private:

    enum ItemStatus{
        ITEM_Standby = 0,
        ITEM_Reading,
        ITEM_Writing,

    };

    struct ItemWrapper{
        T      m_data;
        uint32 m_dataNo;
        uint32 m_timeStamp;
        ItemStatus m_status;
        bool m_isValid;
        ItemWrapper * m_nextItemWrapper;
    };

public:
    RingBuffer(unsigned int bufCap = 0)
        : buffer(NULL)
    {
        create(bufCap);
    }

    ~RingBuffer()
    {
        destroy();
    }

    const T & reserveSendData();
    void sendData();
    const T & getLatestReceivedData();
    const T & getNewXReceivedData();

    /**
     * @brief create  create one buffer
     * @param bufCap  buffer capacity
     * @return  return true if successful
     */
    bool create(unsigned int bufCap)
    {
        if (bufCap == 0)
        {
            return false;
        }

        if (m_buffer != NULL)
        {
            delete m_buffer;
            m_buffer = NULL;
        }

        unsigned int length = bufCap * sizeof(T);
        if(length >= MAX_ASK_FOR_CAP) {
            printf("Memmory allocation exceed limit\n");
            return false;
        }

        m_curBuf = new ItemWrapper();
        memset(m_curBuf, 0, sizeof(ItemWrapper));

        ItemWrapper * tmpS = m_curBuf;
        ItemWrapper * tmp = NULL;
        for(uint8 i = 0; i < bufCap-1; i++) {
            tmp = new ItemWrapper();    
            memset(tmp, 0, sizeof(ItemWrapper)); 
            m_curBuf->m_nextItemWrapper = tmp;
            m_curBuf = tmp;
        }

        m_curBuf->m_nextItemWrapper = tmpS;
        m_curBuf = tmpS;

        bufferInfo.read = 0;
        bufferInfo.write = 0;
        bufferInfo.capacity = bufCap;
        bufferInfo.mask = bufferInfo.capacity - 1;
        return true;
    }

    /**
     * @brief push  write one data of T type into the buffer
     * @param data  one data of T type
     * @return  return true if successful
     */
    bool push(const T &data)
    {
        if (isFull() == true)
        {
            return false;
        }
        int num = memcpy((buffer + bufferInfo.write * sizeof(T)),
                         reinterpret_cast<void*>(&data), sizeof(T));
        if (num == sizeof(T))
        {
            bufferInfo.write += 1;
            return true;
        }
        return false;
    }

    /**
     * @brief push  write serival data of T type into the buffer
     * @param data serival data of T type
     * @param len  length of data
     * @return num of writing to buffer successfully
     */
    unsigned int push(const T *data, unsigned int len)
    {
        if (isFull() == true)
        {
            return 0;
        }
        unsigned int space = availableToWrite();
        if (len > space)
        {
            len = space;
        }
        int num = memcpy((buffer + bufferInfo.write * sizeof(T)),
                         reinterpret_cast<void*>(data), len * sizeof(T));
        bufferInfo.write += num;
        return num;
    }

    /**
     * @brief pop  remove oldest data of the buffer
     * @param num  num of the removed data
     * @return  num of the successful removed data
     */
    unsigned int pop(unsigned int num)
    {
        if (isEmpty() == true)
        {
            return 0;
        }
        unsigned int count = availableToRead();
        if (num < count)
        {
            bufferInfo.read += num;
            return num;
        }
        bufferInfo.read = bufferInfo.write = 0;
        return count;
    }

    /**
     * @brief takeTail  get oldest data of the buffer and remove it
     * @return the data of T type
     */
    T takeTail()
    {
        if (isEmpty() == true)
        {
            return;
        }
        T data = buffer[bufferInfo.read * sizeof(T)];
        pop(1);
        return data;
    }

    /**
     * @brief read  read some oldest data of the buffer and remove them
     * @param buf  read the data to this buf.
     * @param len  read length
     * @return  read legth successfully
     */
    unsigned int read(T &buf, unsigned int len)
    {
        if (sizeof(buf) < len)
        {
            len = sizeof(buf);
        }
        unsigned int count = 0;
        while (isEmpty() == false)
        {
            buf[count++] = this->buffer[bufferInfo.read * sizeof(T)];
            pop(1);
            if (count >= len)
            {
                break;
            }
        }
        return count;
    }

private:
    /**
     * @brief destroy  destroy the buffer created
     */
    void destroy()
    {
        if (buffer == NULL)
        {
            return;
        }
        delete buffer;
        buffer = NULL;
    }

    /**
     * @brief isFull  if be full of the buffer
     * @return   return true if successful
     */
    inline bool isFull() const
    {
        if (0 == availableToWrite())
        {
            return true;
        }
        return false;
    }

    /**
     * @brief isEmpty  if be empty of the buffer
     * @return   return true if successful
     */
    inline bool isEmpty() const
    {
        if (0 == availableToRead())
        {
            return true;
        }
        return false;
    }

    /**
     * @brief availableToRead  available buffer to read
     * @return num of available buffer to read
     */
    inline unsigned int availableToRead() const
    {
        return (bufferInfo.write & bufferInfo.mask)  - (bufferInfo.read & bufferInfo.mask);
    }

    /**
     * @brief availableToWrite  available buffer to write
     * @return num of available buffer to write
     */
    inline unsigned int availableToWrite() const
    {
        return bufferInfo.mask - bufferInfo.mask & bufferInfo.write;
    }

    ItemWrapper *m_curBuf;
    ItemWrapper *m_startBuff;
    ItemWrapper *m_endBuff;
    BufferInfo bufferInfo;
};



#endif



