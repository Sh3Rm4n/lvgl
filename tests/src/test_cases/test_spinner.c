#if LV_BUILD_TEST
#include "../lvgl.h"

#include "unity/unity.h"

static lv_obj_t * active_screen = NULL;
static lv_obj_t * spinner = NULL;

void setUp(void)
{
    active_screen = lv_scr_act();
    spinner = lv_spinner_create(lv_scr_act(), 1000, 60);
    lv_obj_set_size(spinner, 100, 100);
    lv_obj_center(spinner);
}

void tearDown(void)
{
    lv_obj_clean(active_screen);
}

void test_spinner_spinning(void)
{
    for(unsigned char i = 0; i < 10; ++i) {
        lv_tick_inc(50);
        lv_task_handler();

        char filename[16];
        snprintf(filename, sizeof(filename), "spinner_%02u.png", i);
        TEST_ASSERT_EQUAL_SCREENSHOT(filename);
    }
}

#endif
