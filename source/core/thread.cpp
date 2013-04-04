#include "thread.h"

using namespace ecs;

pthread_t ecs::CreateThread(thread_fn* func, void* data)
{
    pthread_t thread;

    pthread_create(&thread, NULL, func, data);

    return thread;
}
