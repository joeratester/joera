/** 
 * header.h : message header structure 
 */

#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdlib.h>

/* define types for variables */
typedef uint16_t msgtype_t;
typedef uint16_t msglen_t;
typedef uint16_t appid_t;
typedef uint16_t result_t;

#define DATESIZE 15
#define SESSIONSIZE 20

/* message_header is an abstract structure
 * response_header and request_header are 
 * real headers. 
 */
struct message_header
{
	msgtype_t message_type;
	msglen_t message_len;
	uint8_t date[DATESIZE]; /* date format : CCYYMMDD-HHMMSS */
};


struct request_header
{
	struct message_header header;
	struct {
		uint8_t major;
		uint8_t minor;
	} version; /* request version */

	appid_t appid; /* application identifier */
	uint8_t sessionid[SESSIONSIZE]; /* session identifier */
};

/* request header functions */

extern int send_request_header(
	const struct request_header *);
extern int receive_request_header(
	struct request_header *);


struct response_header
{
	struct message_header header;
	result_t result;
};

/* response header functions */

extern int send_response_header(
	const struct response_header *);
extern int receive_response_header(
	struct response_header *);

#endif /* HEADER_H */
