#include "thread.h"

using namespace ecs;

pthread_t ecs::CreateThread(thread_fn* func, void* data)
{
    pthread_t thread;

    pthread_create(&thread, NULL, func, data);

    return thread;
}

int ecs::CancelThread(const pthread_t& thread, const long timeout)
{
    if ( timeout == 0 )
        return pthread_join(thread, NULL);

    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    time.tv_nsec += timeout * 1000 * 1000;

    int error = pthread_timedjoin_np(thread, NULL, &time);

    pthread_cancel(thread);
    pthread_join(thread, NULL);

    return error;
}
