#ifndef __CAMERA_INCLUDES_H__
#define __CAMERA_INCLUDES_H__

#include <linux/module.h>
#include <linux/init.h>
#include <linux/pm.h>
#include <linux/fs.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/device.h>
#include <linux/clk.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/regulator/consumer.h>

#include <mach/sys_config.h>
#include <mach/clock.h>
#include "../../../../power/axp_power/axp-gpio.h"

#include "camera_dbg.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define MAX_CAMERA_NUM          2
#define MAX_CAMERA_NAME_LEN     20
#define MAX_NODE_NAME_LEN       20
#define MAX_VDD_STR_LEN         32

#define CSI_MCLK                (24*1000*1000)

typedef unsigned int    __hdle;
typedef unsigned char   __bool;

typedef enum {
    CAMERA_FACING_BACK  = 0,
    CAMERA_FACING_FRONT = 1,    
}__camera_facing_e;

typedef enum {
    CAMERA_CONNECT_SAME_CSI = 0,
    CAMERA_CONNECT_DIFF_CSI = 1,
}__camera_csi_connect_e;

typedef struct {
    __u8                    name[MAX_CAMERA_NAME_LEN];
    
    __u32                   i2c_id;
    __u32                   i2c_addr;
    
    __bool                  pwr_pin_used;
    user_gpio_set_t         pwr_pin[1];
    
    __bool                  stby_pin_used;
    user_gpio_set_t         stby_pin[1];
    
    __bool                  reset_pin_used;
    user_gpio_set_t         reset_pin[1];
    
    __bool                  af_pwr_pin_used;
    user_gpio_set_t         af_pwr_pin[1];
    
    __u8                    iovdd_str[MAX_VDD_STR_LEN];
    struct regulator        *iovdd;
    
    __u8                    avdd_str[MAX_VDD_STR_LEN];
    struct regulator        *avdd;
    
    __u8                    dvdd_str[MAX_VDD_STR_LEN];
    struct regulator        *dvdd;
    
    __camera_facing_e       facing;
    __u8                    drv_node_name[MAX_NODE_NAME_LEN];
    
    struct clk              *module_clk;
    struct clk              *clk_src;
    __hdle                  clk_pin_hdle;
    struct i2c_adapter      *i2c_adap;
}__camera_info_t;

#endif
