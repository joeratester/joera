#ifndef SOCKETIO_H
#define SOCKETIO_H

struct sio_args
{
	int flags;
	unsigned int timeout;   
	unsigned int maxnfails; /* maximum number of fails */
};

/* flags */
#define SIO_NONBLOCK 0x1
#define SIO_VERBOSE 0x2

extern int sio_connect(const char *, int, struct sio_args);
extern int sio_send(int, char *, size_t, struct sio_args);
extern int sio_recv(int, char *, size_t, struct sio_args);


#endif /* SOCKETIO_H */
