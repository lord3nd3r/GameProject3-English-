/* NOTE: original file backed up at /tmp/chinese_backups/Server___Src___ServerEngine___SpinLock.h */
#ifndef __SPIN_LOCK_h__
#define __SPIN_LOCK_h__
#include <atomic>
#include <immintrin.h>
#include <thread>

class CSpinLock
{
public:
    CSpinLock()
    {
#ifdef WIN32
#else
        pthread_spin_init(&m_spinlock, PTHREAD_PROCESS_PRIVATE);
#endif

    };

    ~CSpinLock()
    {
#ifdef WIN32
#else
        pthread_spin_destroy(&m_spinlock);
#endif
    };

    CSpinLock(const CSpinLock&) = delete;
    CSpinLock& operator = (const CSpinLock&) = delete;

    void Lock()
    {
#ifdef WIN32
        while (!m_flag.test_and_set(/*std::memory_order_acquire*/));
#else
        pthread_spin_lock(&m_spinlock);
#endif

        return ;
    }

    void Unlock()
    {
#ifdef WIN32
        m_flag.clear(/*std::memory_order_release*/);
#else
        pthread_spin_unlock(&m_spinlock);
#endif
        return ;
    }

private:
#ifdef WIN32
    std::atomic_flag m_flag = ATOMIC_FLAG_INIT;
#else
    pthread_spinlock_t m_spinlock;
#endif
};

class Spin_lock
{
public:
    Spin_lock(void)
    {
        d_atomic_bool.store(false, std::memory_order_relaxed);
        return;
    }

    void lock(void)
    {
        while (d_atomic_bool.exchange(true, std::memory_order_acquire))
        {
            while (1)
            {
                _mm_pause(); // pause[TRANSLATED][TRANSLATED] [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]12[TRANSLATED][TRANSLATED]
                if (!d_atomic_bool.load(std::memory_order_relaxed))
                {
                    break;
                }
                std::this_thread::yield(); // [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]113[TRANSLATED][TRANSLATED]
                // [TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]，[TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED][TRANSLATED]
                if (!d_atomic_bool.load(std::memory_order_relaxed))
                {
                    break;
                }
                continue;
            }
            continue;
        }
        return;
    }

    bool try_lock(void)
    {
        return !d_atomic_bool.exchange(true, std::memory_order_acquire);
    }

    void unlock(void)
    {
        d_atomic_bool.store(false, std::memory_order_release); // [TRANSLATED][TRANSLATED]isfalse
        return;
    }

private:
    std::atomic<bool> d_atomic_bool;
};

#endif /* __SPIN_LOCK_h__ */

