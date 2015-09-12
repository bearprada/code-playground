/* A common header file to describe the shared memory we wish to pass about. */

#define TEXT_SZ 1024

struct shared_use_st {
    int flag1;
	int flag2;
    int some_text[TEXT_SZ];
};

