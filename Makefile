CFLAGS+=	-std=c99 -Wall -Wextra -pedantic -g
#CFLAGS+=	--analyze
#CCVER=		clang

PROG=	ecached
SRCS=   ecached.c cache.c command.c debug.c hash.c memory.c network.c \
	network_util.c

.include <bsd.prog.mk>
