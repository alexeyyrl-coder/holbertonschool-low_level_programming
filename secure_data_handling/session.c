#include <stdlib.h>
#include <string.h>
#include "session.h"

static char *session_copy_id(const char *id)
{
	char *copy;
	size_t len;

	if (!id)
		return (NULL);

	len = strlen(id) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);

	memcpy(copy, id, len);

	return (copy);
}

session_t *session_create(const char *id, unsigned int uid,
	const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id || (data_len > 0 && !data))
		return (NULL);

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = session_copy_id(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;
	s->data = NULL;
	s->data_len = 0;

	if (data_len == 0)
		return (s);

	s->data = malloc(data_len);
	if (!s->data)
	{
		free(s->id);
		free(s);
		return (NULL);
	}

	memcpy(s->data, data, data_len);
	s->data_len = data_len;

	return (s);
}

int session_set_data(session_t *s, const unsigned char *data,
	size_t data_len)
{
	unsigned char *tmp;

	if (!s || (data_len > 0 && !data))
		return (0);

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	tmp = realloc(s->data, data_len);
	if (!tmp)
		return (0);

	memcpy(tmp, data, data_len);
	s->data = tmp;
	s->data_len = data_len;

	return (1);
}

void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}
