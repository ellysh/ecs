#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

namespace ecs
{

typedef void* (thread_fn) (void *data);

pthread_t CreateThread(thread_fn* function, void* data);

}

#endif
