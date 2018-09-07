/*
 * drivers/video/sunxi/disp2/disp/de/lowlevel_sun8iw9/disp_al.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include "disp_al.h"
#include "de_hal.h"

struct disp_al_private_data
{
	u32 output_type[DEVICE_NUM];//index according to device
	u32 output_mode[DEVICE_NUM];//indicate mode for tv/hdmi, lcd_if for lcd
	u32 output_cs[DEVICE_NUM];//index according to device
	u32 disp_device[DEVICE_NUM];//disp_device[0]=1:indicate disp0 <->device1
	u32 disp_disp[DEVICE_NUM];// disp_disp[0]=1: indicate device0 <-> disp1
	disp_rectsz disp_size[DEVICE_NUM];
	unsigned long long logo_addr[DEVICE_NUM][3];
	disp_rectsz logo_size[DEVICE_NUM];
	disp_layer_info logo_info[DEVICE_NUM];
	u32 output_fps[DEVICE_NUM];//index according to device
	u32 tcon_index[DEVICE_NUM];
};

static struct disp_al_private_data al_priv;

int disp_al_layer_apply(unsigned int disp, struct disp_layer_config_data *data, unsigned int layer_num)
{
	return de_al_lyr_apply(disp, data, layer_num);
}

int disp_al_manager_init(unsigned int disp)
{
	return de_clk_enable(DE_CLK_CORE0 + disp);
}

int disp_al_manager_exit(unsigned int disp)
{
	return de_clk_disable(DE_CLK_CORE0 + disp);
}

int disp_al_manager_apply(unsigned int disp, struct disp_manager_data *data)
{
	if(data->flag & MANAGER_ENABLE_DIRTY) {
		al_priv.output_cs[data->config.disp_device] = data->config.cs;
		al_priv.disp_size[disp].width = data->config.size.width;
		al_priv.disp_size[disp].height = data->config.size.height;
		al_priv.disp_device[disp] = data->config.disp_device;
		al_priv.disp_disp[data->config.disp_device] = disp;
	}

	if (al_priv.output_type[data->config.disp_device] == (u32)DISP_OUTPUT_TYPE_HDMI) {
		if (data->config.cs != 0)//YUV output
			tcon1_hdmi_color_remap(data->config.disp_device,1);
		else
			tcon1_hdmi_color_remap(data->config.disp_device,0);
	}

	return de_al_mgr_apply(disp, data);
}

int disp_al_manager_sync(unsigned int disp)
{
	return de_al_mgr_sync(disp);
}

int disp_al_manager_update_regs(unsigned int disp)
{
	return de_al_mgr_update_regs(disp);
}

int disp_al_manager_query_irq(unsigned int disp)
{
	return de_al_query_irq(disp);
}

int disp_al_manager_enable_irq(unsigned int disp)
{
	return de_al_enable_irq(disp, 1);
}

int disp_al_manager_disable_irq(unsigned int disp)
{
	return de_al_enable_irq(disp, 0);
}

int disp_al_enhance_apply(unsigned int disp, struct disp_enhance_config *config)
{
	if(config->flags & ENHANCE_MODE_DIRTY) {
		struct disp_csc_config csc_config;
		de_dcsc_get_config(disp, &csc_config);
		csc_config.enhance_mode = (config->info.mode >> 16);
		de_dcsc_apply(disp, &csc_config);
	}

	return de_enhance_apply(disp, config);
}

int disp_al_enhance_update_regs(unsigned int disp)
{
	return de_enhance_update_regs(disp);
}

int disp_al_enhance_sync(unsigned int disp)
{
	return de_enhance_sync(disp);
}

int disp_al_enhance_tasklet(unsigned int disp)
{
	return de_enhance_tasklet(disp);
}

int disp_al_capture_init(unsigned int disp)
{
	return de_clk_enable(DE_CLK_WB);
}

int disp_al_capture_exit(unsigned int disp)
{
	return de_clk_disable(DE_CLK_WB);
}

int disp_al_capture_sync(u32 disp)
{
	WB_EBIOS_Update_Regs(disp);
	WB_EBIOS_Writeback_Enable(disp, 1);
	return 0;
}

int disp_al_capture_apply(unsigned int disp, struct disp_capture_config *cfg)
{
	return WB_EBIOS_Apply(disp, cfg);
}

int disp_al_capture_get_status(unsigned int disp)
{
	return WB_EBIOS_Get_Status(disp);
}

int disp_al_smbl_apply(unsigned int disp, struct disp_smbl_info *info)
{
	return de_smbl_apply(disp, info);
}

int disp_al_smbl_update_regs(unsigned int disp)
{
	return de_smbl_update_regs(disp);
}

int disp_al_smbl_sync(unsigned int disp)
{
	return 0;
}

int disp_al_smbl_tasklet(unsigned int disp)
{
	return de_smbl_tasklet(disp);
}

int disp_al_smbl_get_status(unsigned int disp)
{
	return de_smbl_get_status(disp);
}

/*
 * This interface will be called twice.
 * First time, all the freq could be decided by this interface,
 * The second time, all the freq must be adjusted according to the pll_rate.
 * Because not all pll_rate could be supported by system.
 */
int disp_al_lcd_get_clk_info(u32 screen_id, struct lcd_clk_info *info, disp_panel_para * panel)
{
	unsigned long dclk_rate;

	if(NULL == panel) {
		__wrn("panel is NULL\n");
		return 0;
	}

	dclk_rate = panel->lcd_dclk_freq * 1000000;

	switch (panel->lcd_if) {
		case LCD_IF_HV:
			if (0 == info->pll_rate) {
				info->dclk_rate = dclk_rate;
				info->tcon_inner_div = 4;
				info->tcon_rate = dclk_rate * info->tcon_inner_div;
				info->pll_rate = info->tcon_rate * 1;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			} else {
				//info->pll_rate = ;
				info->tcon_inner_div = 4;
				info->tcon_rate = info->pll_rate / 1;
				info->dclk_rate = info->tcon_rate / info->tcon_inner_div;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			}
			break;
		case LCD_IF_CPU:
			if (0 == info->pll_rate) {
				info->dclk_rate = dclk_rate;
				info->tcon_inner_div = 12;
				info->tcon_rate = dclk_rate * info->tcon_inner_div;
				info->pll_rate = info->tcon_rate * 1;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			} else {
				//info->pll_rate = ;
				info->tcon_inner_div = 12;
				info->tcon_rate = info->pll_rate / 1;
				info->dclk_rate = info->tcon_rate / info->tcon_inner_div;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			}
			break;
		case LCD_IF_LVDS:
			if (0 == info->pll_rate) {
				info->dclk_rate = dclk_rate;
				info->tcon_inner_div = 7;
				info->tcon_rate = dclk_rate * info->tcon_inner_div;
				info->pll_rate = info->tcon_rate * 1;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			} else {
				//info->pll_rate = ;
				info->tcon_inner_div = 7;
				info->tcon_rate = info->pll_rate / 1;
				info->dclk_rate = info->tcon_rate / info->tcon_inner_div;
				info->dsi_rate = 0;
				info->dsi_phy_rate = 0;
			}
			break;
		case LCD_IF_DSI:
			if (0 == info->pll_rate) {
				info->dclk_rate = dclk_rate;

				info->tcon_inner_div = 4;
				if(dclk_rate < 35000000)
					info->tcon_inner_div = 10;
				else if((dclk_rate>=35000000)&&(dclk_rate<45000000))
					info->tcon_inner_div = 8;
				else if((dclk_rate>=52000000)&&(dclk_rate<70000000))
					info->tcon_inner_div = 5;
				else if((dclk_rate>=90000000)&&(dclk_rate<100000000))
					info->tcon_inner_div = 3;
				else if((dclk_rate>=140000000)&&(dclk_rate<170000000))
					info->tcon_inner_div = 2;

				info->tcon_rate = dclk_rate * info->tcon_inner_div;
				info->pll_rate = info->tcon_rate * 1;
				info->dsi_rate = info->pll_rate;
				info->dsi_phy_rate = 150000000;
			} else {
				//info->pll_rate = ;

				info->tcon_inner_div = 4;
				if(dclk_rate < 35000000)
					info->tcon_inner_div = 10;
				else if((dclk_rate>=35000000)&&(dclk_rate<45000000))
					info->tcon_inner_div = 8;
				else if((dclk_rate>=52000000)&&(dclk_rate<70000000))
					info->tcon_inner_div = 5;
				else if((dclk_rate>=90000000)&&(dclk_rate<100000000))
					info->tcon_inner_div = 3;
				else if((dclk_rate>=140000000)&&(dclk_rate<170000000))
					info->tcon_inner_div = 2;

				info->tcon_rate = info->pll_rate / 1;
				info->dclk_rate = info->tcon_rate / info->tcon_inner_div;
				info->dsi_rate = info->pll_rate;

				info->dsi_phy_rate = info->pll_rate / 2;
			}
			break;
		default:
			__wrn("Don't support lcd_if %d\n", panel->lcd_if);
	}

	return 0;
}

int disp_al_lcd_cfg(u32 screen_id, disp_panel_para * panel, panel_extend_para *extend_panel)
{
	struct lcd_clk_info info;

	al_priv.output_type[screen_id] = (u32)DISP_OUTPUT_TYPE_LCD;
	al_priv.output_mode[screen_id] = (u32)panel->lcd_if;
	al_priv.output_fps[screen_id] = panel->lcd_dclk_freq * 1000000 / panel->lcd_ht / panel->lcd_vt;
	al_priv.tcon_index[screen_id] = 0;

	de_update_device_fps(al_priv.disp_disp[screen_id], al_priv.output_fps[screen_id]);

	tcon_init(screen_id);
	disp_al_lcd_get_clk_info(screen_id, &info, panel);
	tcon0_set_dclk_div(screen_id, info.tcon_inner_div);

	if(0 != tcon0_cfg(screen_id, panel))
		DE_WRN("lcd cfg fail!\n");
	else
		DE_INF("lcd cfg ok!\n");

	tcon0_cfg_ext(screen_id, extend_panel);

	if(LCD_IF_DSI == panel->lcd_if)	{
#if defined(SUPPORT_DSI)
		if(0 != dsi_cfg(screen_id, panel)) {
			DE_WRN("dsi cfg fail!\n");
		}
#endif
	}

	return 0;
}

int disp_al_lcd_enable(u32 screen_id, disp_panel_para * panel)
{
	tcon0_open(screen_id, panel);
	if(LCD_IF_LVDS == panel->lcd_if) {
		lvds_open(screen_id, panel);
	} else if(LCD_IF_DSI == panel->lcd_if) {
#if defined(SUPPORT_DSI)
		dsi_open(screen_id, panel);
#endif
	}

	return 0;
}

int disp_al_lcd_disable(u32 screen_id, disp_panel_para * panel)
{
	if(LCD_IF_LVDS == panel->lcd_if) {
		lvds_close(screen_id);
	} else if(LCD_IF_DSI == panel->lcd_if) {
#if defined(SUPPORT_DSI)
		dsi_close(screen_id);
#endif
	}
	tcon0_close(screen_id);
	tcon_exit(screen_id);

	return 0;
}

/* query lcd irq, clear it when the irq queried exist
 */
int disp_al_lcd_query_irq(u32 screen_id, __lcd_irq_id_t irq_id, disp_panel_para * panel)
{
	int ret = 0;

#if defined(SUPPORT_DSI) && defined(DSI_VERSION_40)
	if (LCD_IF_DSI == panel->lcd_if) {
		__dsi_irq_id_t dsi_irq = (LCD_IRQ_TCON0_VBLK == irq_id)?DSI_IRQ_VIDEO_VBLK:DSI_IRQ_VIDEO_LINE;
		ret = dsi_irq_query(screen_id, dsi_irq);
	}
	else
#endif
		ret = tcon_irq_query(screen_id, irq_id);

	return ret;
}

int disp_al_lcd_enable_irq(u32 screen_id, __lcd_irq_id_t irq_id, disp_panel_para * panel)
{
	int ret = 0;

#if defined(SUPPORT_DSI) && defined(DSI_VERSION_40)
	if (LCD_IF_DSI == panel->lcd_if) {
		__dsi_irq_id_t dsi_irq = (LCD_IRQ_TCON0_VBLK == irq_id)?DSI_IRQ_VIDEO_VBLK:DSI_IRQ_VIDEO_LINE;

		ret = dsi_irq_enable(screen_id, dsi_irq);
	}
	else
#endif
	ret = tcon_irq_enable(screen_id, irq_id);

	return ret;
}

int disp_al_lcd_disable_irq(u32 screen_id, __lcd_irq_id_t irq_id, disp_panel_para * panel)
{
	int ret = 0;

#if defined(SUPPORT_DSI) && defined(DSI_VERSION_40)
	if (LCD_IF_DSI == panel->lcd_if) {
		__dsi_irq_id_t dsi_irq = (LCD_IRQ_TCON0_VBLK == irq_id)?DSI_IRQ_VIDEO_VBLK:DSI_IRQ_VIDEO_LINE;

		ret = dsi_irq_disable(screen_id, dsi_irq);
	}
	else
#endif
	ret = tcon_irq_disable(screen_id, irq_id);

	return ret;
}

/* take dsi irq s32o account, todo? */
int disp_al_lcd_tri_busy(u32 screen_id, disp_panel_para * panel)
{
	int busy = 0;
	int ret = 0;

	busy |= tcon0_tri_busy(screen_id);
#if defined(SUPPORT_DSI)
	busy |= dsi_inst_busy(screen_id);
#endif
	ret = (busy == 0)? 0:1;

	return (ret);
}
/* take dsi irq s32o account, todo? */
int disp_al_lcd_tri_start(u32 screen_id, disp_panel_para * panel)
{
#if defined(SUPPORT_DSI)
	if(LCD_IF_DSI == panel->lcd_if)
		dsi_tri_start(screen_id);
#endif
	return tcon0_tri_start(screen_id);
}

int disp_al_lcd_io_cfg(u32 screen_id, u32 enable, disp_panel_para * panel)
{
#if defined(SUPPORT_DSI)
	if(LCD_IF_DSI ==  panel->lcd_if) {
		if(enable) {
			dsi_io_open(screen_id, panel);
		} else {
			dsi_io_close(screen_id);
		}
	}
#endif

	return 0;
}

int disp_al_lcd_get_cur_line(u32 screen_id, disp_panel_para * panel)
{
#if defined(SUPPORT_DSI) && defined(DSI_VERSION_40)
	if (LCD_IF_DSI == panel->lcd_if)
		return dsi_get_cur_line(screen_id);
	else
#endif
	return tcon_get_cur_line(screen_id, 0);
}

int disp_al_lcd_get_start_delay(u32 screen_id, disp_panel_para * panel)
{
#if defined(SUPPORT_DSI) && defined(DSI_VERSION_40)
	if (LCD_IF_DSI == panel->lcd_if)
		return dsi_get_start_delay(screen_id);
	else
#endif
	return tcon_get_start_delay(screen_id, 0);
}

/* hdmi */
int disp_al_hdmi_enable(u32 screen_id)
{
	tcon1_open(screen_id);
	return 0;
}

int disp_al_hdmi_disable(u32 screen_id)
{
	tcon1_close(screen_id);
	tcon_exit(screen_id);

	return 0;
}

int disp_al_hdmi_cfg(u32 screen_id, disp_video_timings *video_info)
{
	al_priv.output_type[screen_id] = (u32)DISP_OUTPUT_TYPE_HDMI;
	al_priv.output_mode[screen_id] = (u32)video_info->vic;
	al_priv.output_fps[screen_id] = video_info->pixel_clk / video_info->hor_total_time /\
		video_info->ver_total_time * (video_info->b_interlace + 1) / (video_info->trd_mode + 1);
	al_priv.tcon_index[screen_id] = 1;

	de_update_device_fps(al_priv.disp_disp[screen_id], al_priv.output_fps[screen_id]);

	tcon_init(screen_id);
	tcon1_set_timming(screen_id, video_info);
	if(al_priv.output_cs[screen_id] != 0)//YUV output
		tcon1_hdmi_color_remap(screen_id,1);
	else
		tcon1_hdmi_color_remap(screen_id,0);

	return 0;
}



int disp_al_vdevice_cfg(u32 screen_id, disp_video_timings *video_info, disp_vdevice_interface_para *para)
{
	struct lcd_clk_info clk_info;
	disp_panel_para info;

	if(para->sub_intf == LCD_HV_IF_CCIR656_2CYC){
		al_priv.output_type[screen_id] = (u32)DISP_OUTPUT_TYPE_TV;
	}
	else
		al_priv.output_type[screen_id] = (u32)DISP_OUTPUT_TYPE_LCD;
	al_priv.output_mode[screen_id] = (u32)para->intf;
	al_priv.output_fps[screen_id] = video_info->pixel_clk / video_info->hor_total_time /\
		video_info->ver_total_time;
	al_priv.tcon_index[screen_id] = 0;

	de_update_device_fps(al_priv.disp_disp[screen_id], al_priv.output_fps[screen_id]);

	memset(&info, 0, sizeof(disp_panel_para));
	info.lcd_if = para->intf;
	info.lcd_x = video_info->x_res;
	info.lcd_y = video_info->y_res;
	info.lcd_hv_if = (disp_lcd_hv_if)para->sub_intf;
	info.lcd_dclk_freq = video_info->pixel_clk;
	info.lcd_ht = video_info->hor_total_time;
	info.lcd_hbp = video_info->hor_back_porch + video_info->hor_sync_time;
	info.lcd_hspw = video_info->hor_sync_time;
	info.lcd_vt = video_info->ver_total_time;
	info.lcd_vbp = video_info->ver_back_porch + video_info->ver_sync_time;
	info.lcd_vspw = video_info->ver_sync_time;
	info.lcd_interlace = video_info->b_interlace;
	info.lcd_hv_syuv_fdly = para->fdelay;
	info.lcd_hv_clk_phase = para->clk_phase;
	info.lcd_hv_sync_polarity = para->sync_polarity;

	if(LCD_HV_IF_CCIR656_2CYC == info.lcd_hv_if)
		info.lcd_hv_syuv_seq = para->sequence;
	else
		info.lcd_hv_srgb_seq = para->sequence;
	tcon_init(screen_id);
	disp_al_lcd_get_clk_info(screen_id, &clk_info, &info);

	clk_info.tcon_inner_div = 8;//fixme
	tcon0_set_dclk_div(screen_id, clk_info.tcon_inner_div);
	if(para->sub_intf == LCD_HV_IF_CCIR656_2CYC)
		tcon1_yuv_range(screen_id, 1);
	if(0 != tcon0_cfg(screen_id, &info))
		DE_WRN("lcd cfg fail!\n");
	else
		DE_INF("lcd cfg ok!\n");

	return 0;
}

int disp_al_vdevice_enable(u32 screen_id)
{
	disp_panel_para panel;

	memset(&panel, 0, sizeof(disp_panel_para));
	panel.lcd_if = LCD_IF_HV;
	tcon0_open(screen_id, &panel);

	return 0;
}

int disp_al_vdevice_disable(u32 screen_id)
{
	tcon0_close(screen_id);
	tcon_exit(screen_id);

	return 0;
}

/* screen_id: used for index of manager */
int disp_al_device_get_cur_line(u32 screen_id)
{
	u32 tcon_index = al_priv.tcon_index[screen_id];

	return tcon_get_cur_line(screen_id, tcon_index);
}

int disp_al_device_get_start_delay(u32 screen_id)
{
	u32 tcon_index = al_priv.tcon_index[screen_id];
	return tcon_get_start_delay(screen_id, tcon_index);
}

int disp_al_device_query_irq(u32 screen_id)
{
	int ret = 0;
	int irq_id = 0;

	irq_id = (al_priv.tcon_index[screen_id] == 0)?\
		LCD_IRQ_TCON0_VBLK:LCD_IRQ_TCON1_VBLK;
	ret = tcon_irq_query(screen_id, irq_id);

	return ret;
}

int disp_al_device_enable_irq(u32 screen_id)
{
	int ret = 0;
	int irq_id = 0;

	irq_id = (al_priv.tcon_index[screen_id] == 0)?\
		LCD_IRQ_TCON0_VBLK:LCD_IRQ_TCON1_VBLK;
	ret = tcon_irq_enable(screen_id, irq_id);

	return ret;
}

int disp_al_device_disable_irq(u32 screen_id)
{
	int ret = 0;
	int irq_id = 0;

	irq_id = (al_priv.tcon_index[screen_id] == 0)?\
		LCD_IRQ_TCON0_VBLK:LCD_IRQ_TCON1_VBLK;
	ret = tcon_irq_disable(screen_id, irq_id);

	return ret;
}

int disp_al_device_get_status(u32 screen_id)
{
	int ret = 0;

	ret = tcon_get_status(screen_id, al_priv.tcon_index[screen_id]);

	return ret;
}

int disp_init_al(disp_bsp_init_para * para)
{
	int i;

	memset(&al_priv, 0, sizeof(struct disp_al_private_data));
	de_al_init(para);
	de_enhance_init(para);
	de_ccsc_init(para);
	de_dcsc_init(para);
	WB_EBIOS_Init(para);
	de_clk_set_reg_base(para->reg_base[DISP_MOD_DE]);

	for(i=0; i<DEVICE_NUM; i++) {
		tcon_set_reg_base(i, para->reg_base[DISP_MOD_LCD0]);//calc lcd1 base
		de_smbl_init(i, para->reg_base[DISP_MOD_DE]);
	}

#if defined(SUPPORT_DSI)
	dsi_set_reg_base(0, para->reg_base[DISP_MOD_DSI0]);
#endif

	if(1 == para->boot_info.sync) {
		u32 disp = para->boot_info.disp;
		u32 chn,layer_id;
		u32 chn_num = de_feat_get_num_chns(disp);
		u32 layer_num;
		u32 logo_find = 0;
		u32 disp_device;
		disp_video_timings tt;

		memset(&tt, 0, sizeof(disp_video_timings));
		al_priv.disp_device[disp] = de_rtmx_get_mux(disp);
		disp_device = al_priv.disp_device[disp];

		/* should take care about this, extend display treated as a LCD OUTPUT */
		al_priv.output_type[disp_device] = para->boot_info.type;
		al_priv.output_mode[disp_device] = para->boot_info.mode;
		al_priv.tcon_index[disp_device] = 0;
#if defined(SUPPORT_HDMI)
		al_priv.tcon_index[disp_device] = (DISP_OUTPUT_TYPE_HDMI == para->boot_info.type)?1:al_priv.tcon_index[disp_device];
#endif
#if defined(SUPPORT_TV)
		al_priv.tcon_index[disp_device] = (DISP_OUTPUT_TYPE_TV == para->boot_info.type)?1:al_priv.tcon_index[disp_device];
#endif

		de_rtmx_sync_hw(disp);
		de_rtmx_get_display_size(disp, &al_priv.disp_size[disp].width, &al_priv.disp_size[disp].height);
		for(chn=0; chn<chn_num; chn++) {
			layer_num = de_feat_get_num_layers_by_chn(disp, chn);
			for(layer_id=0; layer_id<layer_num; layer_id++) {
				if(de_rtmx_get_lay_enabled(disp, chn, layer_id)) {
					logo_find = 1;
					break;
				}
			}
			if(logo_find)
				break;
		}

		if(logo_find) {
			disp_rect win;
			de_rtmx_get_lay_size(disp, chn, layer_id, al_priv.logo_info[disp].fb.size);
			de_rtmx_get_lay_address(disp, chn, layer_id, al_priv.logo_info[disp].fb.addr);
			de_rtmx_get_lay_win(disp, chn, layer_id, &win);
			al_priv.logo_info[disp].fb.format = de_rtmx_get_lay_format(disp, chn, layer_id);
			al_priv.logo_info[disp].fb.crop.width = ((long long)win.width)<<32;
			al_priv.logo_info[disp].fb.crop.height = ((long long)win.height)<<32;
		}
		al_priv.output_fps[disp_device] = 60;
		de_update_device_fps(disp, al_priv.output_fps[disp_device]);
	}

	return 0;
}

int disp_al_get_fb_info(unsigned int sel, disp_layer_info *info)
{
	memcpy(info, &al_priv.logo_info[sel], sizeof(disp_layer_info));
	return 0;
}

int disp_al_get_display_size(unsigned int screen_id, unsigned int *width, unsigned int *height)
{
	*width = al_priv.disp_size[screen_id].width;
	*height = al_priv.disp_size[screen_id].height;

	return 0;
}

