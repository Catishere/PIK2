#ifndef MACROS_H
#define MACROS_H

#define FAKE_DB_FILE "statistics.dat"

#define ASSERT_WRONG(val, wrong_val, error)\
        if (val == wrong_val)\
        {\
            perror(error);\
            return 1;\
        }

#define ASSERT_TRUE(val, true_val, error)\
        if (val != true_val)\
        {\
            perror(error);\
            return 1;\
        }

#define INPUT_FIELD(title, field, size)\
        printf(title": ");\
        readline(field, size);

#define FILTER(l, exp)\
        l->current = l->first;\
        do {\
            exp;\
        } while (next(l) != NULL);


#endif // MACROS_H
