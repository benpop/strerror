#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct {
    const char *name;
    const int code;
} static const errors[] = {
    { "EPERM", EPERM },
    { "ENOENT", ENOENT },
    { "ESRCH", ESRCH },
    { "EINTR", EINTR },
    { "EIO", EIO },
    { "ENXIO", ENXIO },
    { "E2BIG", E2BIG },
    { "ENOEXEC", ENOEXEC },
    { "EBADF", EBADF },
    { "ECHILD", ECHILD },
    { "EAGAIN", EAGAIN },
    { "ENOMEM", ENOMEM },
    { "EACCES", EACCES },
    { "EFAULT", EFAULT },
    { "ENOTBLK", ENOTBLK },
    { "EBUSY", EBUSY },
    { "EEXIST", EEXIST },
    { "EXDEV", EXDEV },
    { "ENODEV", ENODEV },
    { "ENOTDIR", ENOTDIR },
    { "EISDIR", EISDIR },
    { "EINVAL", EINVAL },
    { "ENFILE", ENFILE },
    { "EMFILE", EMFILE },
    { "ENOTTY", ENOTTY },
    { "ETXTBSY", ETXTBSY },
    { "EFBIG", EFBIG },
    { "ENOSPC", ENOSPC },
    { "ESPIPE", ESPIPE },
    { "EROFS", EROFS },
    { "EMLINK", EMLINK },
    { "EPIPE", EPIPE },
    { "EDOM", EDOM },
    { "ERANGE", ERANGE },
    { "EDEADLK", EDEADLK },
    { "ENAMETOOLONG", ENAMETOOLONG },
    { "ENOLCK", ENOLCK },
    { "ENOSYS", ENOSYS },
    { "ENOTEMPTY", ENOTEMPTY },
    { "ELOOP", ELOOP },
    { "EWOULDBLOCK", EWOULDBLOCK },
    { "ENOMSG", ENOMSG },
    { "EIDRM", EIDRM },
#ifdef OS_Linux
    { "ECHRNG", ECHRNG },
    { "EL2NSYNC", EL2NSYNC },
    { "EL3HLT", EL3HLT },
    { "EL3RST", EL3RST },
    { "ELNRNG", ELNRNG },
    { "EUNATCH", EUNATCH },
    { "ENOCSI", ENOCSI },
    { "EL2HLT", EL2HLT },
    { "EBADE", EBADE },
    { "EBADR", EBADR },
    { "EXFULL", EXFULL },
    { "ENOANO", ENOANO },
    { "EBADRQC", EBADRQC },
    { "EBADSLT", EBADSLT },
    { "EDEADLOCK", EDEADLOCK },
    { "EBFONT", EBFONT },
    { "ENONET", ENONET },
    { "ENOPKG", ENOPKG },
    { "EADV", EADV },
    { "ESRMNT", ESRMNT },
    { "ECOMM", ECOMM },
    { "EDOTDOT", EDOTDOT },
    { "ENOTUNIQ", ENOTUNIQ },
    { "EBADFD", EBADFD },
    { "EREMCHG", EREMCHG },
    { "ELIBACC", ELIBACC },
    { "ELIBBAD", ELIBBAD },
    { "ELIBSCN", ELIBSCN },
    { "ELIBMAX", ELIBMAX },
    { "ELIBEXEC", ELIBEXEC },
    { "ERESTART", ERESTART },
    { "ESTRPIPE", ESTRPIPE },
    { "EUCLEAN", EUCLEAN },
    { "ENOTNAM", ENOTNAM },
    { "ENAVAIL", ENAVAIL },
    { "EISNAM", EISNAM },
    { "EREMOTEIO", EREMOTEIO },
    { "EDQUOT", EDQUOT },
    { "ENOMEDIUM", ENOMEDIUM },
    { "EMEDIUMTYPE", EMEDIUMTYPE },
    { "ENOKEY", ENOKEY },
    { "EKEYEXPIRED", EKEYEXPIRED },
    { "EKEYREVOKED", EKEYREVOKED },
    { "EKEYREJECTED", EKEYREJECTED },
    { "ERFKILL", ERFKILL },
    { "EHWPOISON", EHWPOISON },
#endif
    { "ENOSTR", ENOSTR },
    { "ENODATA", ENODATA },
    { "ETIME", ETIME },
    { "ENOSR", ENOSR },
    { "EREMOTE", EREMOTE },
    { "ENOLINK", ENOLINK },
    { "EPROTO", EPROTO },
    { "EMULTIHOP", EMULTIHOP },
    { "EBADMSG", EBADMSG },
    { "EOVERFLOW", EOVERFLOW },
    { "EILSEQ", EILSEQ },
    { "EUSERS", EUSERS },
    { "ENOTSOCK", ENOTSOCK },
    { "EDESTADDRREQ", EDESTADDRREQ },
    { "EMSGSIZE", EMSGSIZE },
    { "EPROTOTYPE", EPROTOTYPE },
    { "ENOPROTOOPT", ENOPROTOOPT },
    { "EPROTONOSUPPORT", EPROTONOSUPPORT },
    { "ESOCKTNOSUPPORT", ESOCKTNOSUPPORT },
    { "EOPNOTSUPP", EOPNOTSUPP },
    { "EPFNOSUPPORT", EPFNOSUPPORT },
    { "EAFNOSUPPORT", EAFNOSUPPORT },
    { "EADDRINUSE", EADDRINUSE },
    { "EADDRNOTAVAIL", EADDRNOTAVAIL },
    { "ENETDOWN", ENETDOWN },
    { "ENETUNREACH", ENETUNREACH },
    { "ENETRESET", ENETRESET },
    { "ECONNABORTED", ECONNABORTED },
    { "ECONNRESET", ECONNRESET },
    { "ENOBUFS", ENOBUFS },
    { "EISCONN", EISCONN },
    { "ENOTCONN", ENOTCONN },
    { "ESHUTDOWN", ESHUTDOWN },
    { "ETOOMANYREFS", ETOOMANYREFS },
    { "ETIMEDOUT", ETIMEDOUT },
    { "ECONNREFUSED", ECONNREFUSED },
    { "EHOSTDOWN", EHOSTDOWN },
    { "EHOSTUNREACH", EHOSTUNREACH },
    { "EALREADY", EALREADY },
    { "EINPROGRESS", EINPROGRESS },
    { "ESTALE", ESTALE },
    { "ECANCELED", ECANCELED },
    { "EOWNERDEAD", EOWNERDEAD },
    { "ENOTRECOVERABLE", ENOTRECOVERABLE },
    { 0, -1 }
};

int main(int argc, char **argv)
{
    int i, err, j;
    for (i=1; i<argc; ++i) {
        err = atoi(argv[i]);
        if (!err) {
            for (j=0; errors[j].name; ++j) {
                if (!strcasecmp(argv[i], errors[j].name)) {
                    err = errors[j].code;
                    break;
                }
            }
        }
        if (!err) {
            printf("Can't parse %s\n", argv[i]);
        } else {
            const char *str = strerror(err);
            if (!str) {
                printf("Can't find %s\n", argv[i]);
            } else {
                printf("%d:", err);
                for (j=0; errors[j].name; ++j) {
                    if (err == errors[j].code) {
                        printf(" %s", errors[j].name);
                        // there can be aliases
                    }
                }
                printf(" \"%s\"\n", str);
            }
        }
    }
    return 0;
}
