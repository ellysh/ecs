#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

namespace ecs
{

typedef void* (thread_fn) (void *data);

pthread_t CreateThread(const thread_fn* function, void* data);
int CancelThread(const pthread_t& thread, const long timeout);

}

#endif
