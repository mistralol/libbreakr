

#define LOCK(x) { pthread_mutex_lock(x); }
#define UNLOCK(x) { pthread_mutex_unlock(x); }

extern void breakr_activate();
extern void breakr_deactive();
extern void breakr_action(const char *function);

