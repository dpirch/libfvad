#include "test_common.h"
#include <stdio.h>

void assert_fail(const char *s, const char *file, int line)
{
    printf("failed ASSERT: %s (%s:%d)\n", s, file, line);
    exit(1);
}

static bool expect_failed = false;

void expect_fail(const char *s, const char *file, int line)
{
    printf("failed EXPECT: %s (%s:%d)\n", s, file, line);
    expect_failed = true;
}

// function to be defined by individual tests
void test_main(void);

int main(int argc, char *argv[])
{
    test_main();
    if (expect_failed) exit(2);
}
