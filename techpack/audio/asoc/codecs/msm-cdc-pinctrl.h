/* Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MFD_CDC_PINCTRL_H_
#define __MFD_CDC_PINCTRL_H_

#include <linux/types.h>
#include <linux/of.h>

#if IS_ENABLED(CONFIG_MSM_CDC_PINCTRL)
extern int msm_cdc_pinctrl_select_sleep_state(struct device_node *np);
extern int msm_cdc_pinctrl_select_active_state(struct device_node *np);
extern bool msm_cdc_pinctrl_get_state(struct device_node *np);
extern int msm_cdc_get_gpio_state(struct device_node *np);
int msm_cdc_pinctrl_drv_init(void);
void msm_cdc_pinctrl_drv_exit(void);

#else
int msm_cdc_pinctrl_select_sleep_state(struct device_node *np)
{
	return 0;
}
int msm_cdc_pinctrl_select_active_state(struct device_node *np)
{
	return 0;
}
int msm_cdc_get_gpio_state(struct device_node *np)
{
	return 0;
}
int msm_cdc_pinctrl_drv_init(void)
{
	return 0;
}
void msm_cdc_pinctrl_drv_exit(void)
{
}
#endif

/* bootleg to support cs35l35*/
enum pinctrl_client {
	CLIENT_WCD_INT,
	CLIENT_WCD_EXT,
	CLIENT_WSA_BONGO_1,
	CLIENT_WSA_BONGO_2,
	MAX_PINCTRL_CLIENT,
};


/* finds the index for the gpio set in the dtsi file */
int msm_get_gpioset_index(enum pinctrl_client client, char *keyword);

/*
 * this function reads the following from dtsi file
 * 1. all gpio sets
 * 2. all combinations of gpio sets
 * 3. pinctrl handles to gpio sets
 *
 * returns error if there is
 * 1. problem reading from dtsi file
 * 2. memory allocation failure
 */
int msm_gpioset_initialize(enum pinctrl_client client, struct device *dev);

int msm_gpioset_activate(enum pinctrl_client client, char *keyword);

int msm_gpioset_suspend(enum pinctrl_client client, char *keyword);


#endif
