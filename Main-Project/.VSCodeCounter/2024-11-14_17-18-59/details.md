# Details

Date : 2024-11-14 17:18:59

Directory /Users/danieldew/Documents/GitHub/High-Stakes-Code/Main-Project

Total : 247 files,  40754 codes, 45772 comments, 10845 blanks, all 97371 lines

[Summary](results.md) / Details / [Diff Summary](diff.md) / [Diff Details](diff-details.md)

## Files
| filename | language | code | comment | blank | total |
| :--- | :--- | ---: | ---: | ---: | ---: |
| [Makefile](/Makefile) | Makefile | 20 | 19 | 9 | 48 |
| [common.mk](/common.mk) | Makefile | 241 | 14 | 54 | 309 |
| [firmware/hot-cold-asset.mk](/firmware/hot-cold-asset.mk) | Makefile | 14 | 1 | 4 | 19 |
| [include/api.h](/include/api.h) | C++ | 61 | 17 | 8 | 86 |
| [include/fmt/args.h](/include/fmt/args.h) | C++ | 108 | 67 | 33 | 208 |
| [include/fmt/core.h](/include/fmt/core.h) | C++ | 1,847 | 339 | 481 | 2,667 |
| [include/fmt/format-inl.h](/include/fmt/format-inl.h) | C++ | 1,300 | 109 | 130 | 1,539 |
| [include/fmt/format.h](/include/fmt/format.h) | C++ | 3,054 | 533 | 527 | 4,114 |
| [include/lemlib/api.hpp](/include/lemlib/api.hpp) | C++ | 9 | 2 | 3 | 14 |
| [include/lemlib/asset.hpp](/include/lemlib/asset.hpp) | C++ | 22 | 0 | 6 | 28 |
| [include/lemlib/chassis/chassis.hpp](/include/lemlib/chassis/chassis.hpp) | C++ | 160 | 768 | 23 | 951 |
| [include/lemlib/chassis/odom.hpp](/include/lemlib/chassis/odom.hpp) | C++ | 13 | 45 | 3 | 61 |
| [include/lemlib/chassis/trackingWheel.hpp](/include/lemlib/chassis/trackingWheel.hpp) | C++ | 40 | 152 | 4 | 196 |
| [include/lemlib/driveCurve.hpp](/include/lemlib/driveCurve.hpp) | C++ | 15 | 58 | 2 | 75 |
| [include/lemlib/exitcondition.hpp](/include/lemlib/exitcondition.hpp) | C++ | 15 | 52 | 1 | 68 |
| [include/lemlib/logger/baseSink.hpp](/include/lemlib/logger/baseSink.hpp) | C++ | 54 | 134 | 22 | 210 |
| [include/lemlib/logger/buffer.hpp](/include/lemlib/logger/buffer.hpp) | C++ | 24 | 36 | 13 | 73 |
| [include/lemlib/logger/infoSink.hpp](/include/lemlib/logger/infoSink.hpp) | C++ | 11 | 23 | 3 | 37 |
| [include/lemlib/logger/logger.hpp](/include/lemlib/logger/logger.hpp) | C++ | 12 | 8 | 7 | 27 |
| [include/lemlib/logger/message.hpp](/include/lemlib/logger/message.hpp) | C++ | 12 | 17 | 7 | 36 |
| [include/lemlib/logger/stdout.hpp](/include/lemlib/logger/stdout.hpp) | C++ | 14 | 15 | 6 | 35 |
| [include/lemlib/logger/telemetrySink.hpp](/include/lemlib/logger/telemetrySink.hpp) | C++ | 10 | 22 | 3 | 35 |
| [include/lemlib/pid.hpp](/include/lemlib/pid.hpp) | C++ | 17 | 54 | 5 | 76 |
| [include/lemlib/pose.hpp](/include/lemlib/pose.hpp) | C++ | 21 | 194 | 4 | 219 |
| [include/lemlib/timer.hpp](/include/lemlib/timer.hpp) | C++ | 23 | 175 | 2 | 200 |
| [include/lemlib/util.hpp](/include/lemlib/util.hpp) | C++ | 17 | 139 | 10 | 166 |
| [include/liblvgl/core/lv_disp.h](/include/liblvgl/core/lv_disp.h) | C++ | 77 | 150 | 38 | 265 |
| [include/liblvgl/core/lv_event.h](/include/liblvgl/core/lv_event.h) | C++ | 110 | 203 | 51 | 364 |
| [include/liblvgl/core/lv_group.h](/include/liblvgl/core/lv_group.h) | C++ | 75 | 145 | 47 | 267 |
| [include/liblvgl/core/lv_indev.h](/include/liblvgl/core/lv_indev.h) | C++ | 31 | 117 | 29 | 177 |
| [include/liblvgl/core/lv_indev_scroll.h](/include/liblvgl/core/lv_indev_scroll.h) | C++ | 14 | 38 | 14 | 66 |
| [include/liblvgl/core/lv_obj.h](/include/liblvgl/core/lv_obj.h) | C++ | 179 | 165 | 66 | 410 |
| [include/liblvgl/core/lv_obj_class.h](/include/liblvgl/core/lv_obj_class.h) | C++ | 45 | 29 | 21 | 95 |
| [include/liblvgl/core/lv_obj_draw.h](/include/liblvgl/core/lv_obj_draw.h) | C++ | 59 | 87 | 27 | 173 |
| [include/liblvgl/core/lv_obj_pos.h](/include/liblvgl/core/lv_obj_pos.h) | C++ | 67 | 323 | 60 | 450 |
| [include/liblvgl/core/lv_obj_scroll.h](/include/liblvgl/core/lv_obj_scroll.h) | C++ | 55 | 207 | 46 | 308 |
| [include/liblvgl/core/lv_obj_style.h](/include/liblvgl/core/lv_obj_style.h) | C++ | 91 | 117 | 41 | 249 |
| [include/liblvgl/core/lv_obj_style_gen.h](/include/liblvgl/core/lv_obj_style_gen.h) | C++ | 554 | 0 | 95 | 649 |
| [include/liblvgl/core/lv_obj_tree.h](/include/liblvgl/core/lv_obj_tree.h) | C++ | 34 | 109 | 30 | 173 |
| [include/liblvgl/core/lv_refr.h](/include/liblvgl/core/lv_refr.h) | C++ | 23 | 70 | 23 | 116 |
| [include/liblvgl/core/lv_theme.h](/include/liblvgl/core/lv_theme.h) | C++ | 34 | 66 | 21 | 121 |
| [include/liblvgl/draw/arm2d/lv_gpu_arm2d.h](/include/liblvgl/draw/arm2d/lv_gpu_arm2d.h) | C++ | 18 | 19 | 15 | 52 |
| [include/liblvgl/draw/lv_draw.h](/include/liblvgl/draw/lv_draw.h) | C++ | 78 | 97 | 44 | 219 |
| [include/liblvgl/draw/lv_draw_arc.h](/include/liblvgl/draw/lv_draw_arc.h) | C++ | 29 | 41 | 14 | 84 |
| [include/liblvgl/draw/lv_draw_img.h](/include/liblvgl/draw/lv_draw_img.h) | C++ | 33 | 49 | 23 | 105 |
| [include/liblvgl/draw/lv_draw_label.h](/include/liblvgl/draw/lv_draw_label.h) | C++ | 43 | 40 | 18 | 101 |
| [include/liblvgl/draw/lv_draw_layer.h](/include/liblvgl/draw/lv_draw_layer.h) | C++ | 24 | 45 | 15 | 84 |
| [include/liblvgl/draw/lv_draw_line.h](/include/liblvgl/draw/lv_draw_line.h) | C++ | 28 | 26 | 14 | 68 |
| [include/liblvgl/draw/lv_draw_mask.h](/include/liblvgl/draw/lv_draw_mask.h) | C++ | 159 | 158 | 78 | 395 |
| [include/liblvgl/draw/lv_draw_rect.h](/include/liblvgl/draw/lv_draw_rect.h) | C++ | 47 | 30 | 20 | 97 |
| [include/liblvgl/draw/lv_draw_transform.h](/include/liblvgl/draw/lv_draw_transform.h) | C++ | 15 | 19 | 11 | 45 |
| [include/liblvgl/draw/lv_draw_triangle.h](/include/liblvgl/draw/lv_draw_triangle.h) | C++ | 13 | 19 | 11 | 43 |
| [include/liblvgl/draw/lv_img_buf.h](/include/liblvgl/draw/lv_img_buf.h) | C++ | 104 | 107 | 39 | 250 |
| [include/liblvgl/draw/lv_img_cache.h](/include/liblvgl/draw/lv_img_cache.h) | C++ | 17 | 47 | 15 | 79 |
| [include/liblvgl/draw/lv_img_decoder.h](/include/liblvgl/draw/lv_img_decoder.h) | C++ | 68 | 160 | 47 | 275 |
| [include/liblvgl/draw/nxp/lv_gpu_nxp.h](/include/liblvgl/draw/nxp/lv_gpu_nxp.h) | C++ | 16 | 42 | 14 | 72 |
| [include/liblvgl/draw/nxp/pxp/lv_draw_pxp_blend.h](/include/liblvgl/draw/nxp/pxp/lv_draw_pxp_blend.h) | C++ | 35 | 87 | 22 | 144 |
| [include/liblvgl/draw/nxp/pxp/lv_gpu_nxp_pxp.h](/include/liblvgl/draw/nxp/pxp/lv_gpu_nxp_pxp.h) | C++ | 60 | 66 | 28 | 154 |
| [include/liblvgl/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.h](/include/liblvgl/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.h) | C++ | 15 | 48 | 16 | 79 |
| [include/liblvgl/draw/nxp/vglite/lv_draw_vglite_arc.h](/include/liblvgl/draw/nxp/vglite/lv_draw_vglite_arc.h) | C++ | 15 | 51 | 14 | 80 |
| [include/liblvgl/draw/nxp/vglite/lv_draw_vglite_blend.h](/include/liblvgl/draw/nxp/vglite/lv_draw_vglite_blend.h) | C++ | 48 | 76 | 26 | 150 |
| [include/liblvgl/draw/nxp/vglite/lv_draw_vglite_rect.h](/include/liblvgl/draw/nxp/vglite/lv_draw_vglite_rect.h) | C++ | 15 | 49 | 14 | 78 |
| [include/liblvgl/draw/nxp/vglite/lv_gpu_nxp_vglite.h](/include/liblvgl/draw/nxp/vglite/lv_gpu_nxp_vglite.h) | C++ | 82 | 75 | 29 | 186 |
| [include/liblvgl/draw/sdl/lv_draw_sdl.h](/include/liblvgl/draw/sdl/lv_draw_sdl.h) | C++ | 33 | 38 | 26 | 97 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_composite.h](/include/liblvgl/draw/sdl/lv_draw_sdl_composite.h) | C++ | 27 | 30 | 17 | 74 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_img.h](/include/liblvgl/draw/sdl/lv_draw_sdl_img.h) | C++ | 22 | 31 | 20 | 73 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_layer.h](/include/liblvgl/draw/sdl/lv_draw_sdl_layer.h) | C++ | 24 | 19 | 13 | 56 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_mask.h](/include/liblvgl/draw/sdl/lv_draw_sdl_mask.h) | C++ | 17 | 19 | 16 | 52 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_priv.h](/include/liblvgl/draw/sdl/lv_draw_sdl_priv.h) | C++ | 22 | 31 | 20 | 73 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_rect.h](/include/liblvgl/draw/sdl/lv_draw_sdl_rect.h) | C++ | 22 | 31 | 23 | 76 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_stack_blur.h](/include/liblvgl/draw/sdl/lv_draw_sdl_stack_blur.h) | C++ | 14 | 19 | 14 | 47 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_texture_cache.h](/include/liblvgl/draw/sdl/lv_draw_sdl_texture_cache.h) | C++ | 56 | 22 | 25 | 103 |
| [include/liblvgl/draw/sdl/lv_draw_sdl_utils.h](/include/liblvgl/draw/sdl/lv_draw_sdl_utils.h) | C++ | 26 | 19 | 21 | 66 |
| [include/liblvgl/draw/stm32_dma2d/lv_gpu_stm32_dma2d.h](/include/liblvgl/draw/stm32_dma2d/lv_gpu_stm32_dma2d.h) | C++ | 29 | 22 | 20 | 71 |
| [include/liblvgl/draw/sw/lv_draw_sw.h](/include/liblvgl/draw/sw/lv_draw_sw.h) | C++ | 52 | 23 | 30 | 105 |
| [include/liblvgl/draw/sw/lv_draw_sw_blend.h](/include/liblvgl/draw/sw/lv_draw_sw_blend.h) | C++ | 26 | 30 | 14 | 70 |
| [include/liblvgl/draw/sw/lv_draw_sw_dither.h](/include/liblvgl/draw/sw/lv_draw_sw_dither.h) | C++ | 37 | 17 | 17 | 71 |
| [include/liblvgl/draw/sw/lv_draw_sw_gradient.h](/include/liblvgl/draw/sw/lv_draw_sw_gradient.h) | C++ | 42 | 40 | 16 | 98 |
| [include/liblvgl/draw/swm341_dma2d/lv_gpu_swm341_dma2d.h](/include/liblvgl/draw/swm341_dma2d/lv_gpu_swm341_dma2d.h) | C++ | 24 | 22 | 19 | 65 |
| [include/liblvgl/extra/layouts/flex/lv_flex.h](/include/liblvgl/extra/layouts/flex/lv_flex.h) | C++ | 82 | 44 | 27 | 153 |
| [include/liblvgl/extra/layouts/grid/lv_grid.h](/include/liblvgl/extra/layouts/grid/lv_grid.h) | C++ | 117 | 44 | 34 | 195 |
| [include/liblvgl/extra/layouts/lv_layouts.h](/include/liblvgl/extra/layouts/lv_layouts.h) | C++ | 16 | 19 | 10 | 45 |
| [include/liblvgl/extra/libs/bmp/lv_bmp.h](/include/liblvgl/extra/libs/bmp/lv_bmp.h) | C++ | 13 | 19 | 11 | 43 |
| [include/liblvgl/extra/libs/ffmpeg/lv_ffmpeg.h](/include/liblvgl/extra/libs/ffmpeg/lv_ffmpeg.h) | C++ | 34 | 51 | 20 | 105 |
| [include/liblvgl/extra/libs/freetype/lv_freetype.h](/include/liblvgl/extra/libs/freetype/lv_freetype.h) | C++ | 29 | 40 | 15 | 84 |
| [include/liblvgl/extra/libs/fsdrv/lv_fsdrv.h](/include/liblvgl/extra/libs/fsdrv/lv_fsdrv.h) | C++ | 22 | 19 | 15 | 56 |
| [include/liblvgl/extra/libs/gif/gifdec.h](/include/liblvgl/extra/libs/gif/gifdec.h) | C++ | 47 | 0 | 14 | 61 |
| [include/liblvgl/extra/libs/gif/lv_gif.h](/include/liblvgl/extra/libs/gif/lv_gif.h) | C++ | 24 | 19 | 16 | 59 |
| [include/liblvgl/extra/libs/lv_libs.h](/include/liblvgl/extra/libs/lv_libs.h) | C++ | 18 | 19 | 10 | 47 |
| [include/liblvgl/extra/libs/png/lodepng.h](/include/liblvgl/extra/libs/png/lodepng.h) | C++ | 437 | 1,414 | 131 | 1,982 |
| [include/liblvgl/extra/libs/png/lv_png.h](/include/liblvgl/extra/libs/png/lv_png.h) | C++ | 13 | 22 | 12 | 47 |
| [include/liblvgl/extra/libs/qrcode/lv_qrcode.h](/include/liblvgl/extra/libs/qrcode/lv_qrcode.h) | C++ | 16 | 39 | 15 | 70 |
| [include/liblvgl/extra/libs/qrcode/qrcodegen.h](/include/liblvgl/extra/libs/qrcode/qrcodegen.h) | C++ | 63 | 200 | 57 | 320 |
| [include/liblvgl/extra/libs/rlottie/lv_rlottie.h](/include/liblvgl/extra/libs/rlottie/lv_rlottie.h) | C++ | 40 | 20 | 16 | 76 |
| [include/liblvgl/extra/libs/sjpg/lv_sjpg.h](/include/liblvgl/extra/libs/sjpg/lv_sjpg.h) | C++ | 12 | 19 | 13 | 44 |
| [include/liblvgl/extra/libs/sjpg/tjpgd.h](/include/liblvgl/extra/libs/sjpg/tjpgd.h) | C++ | 72 | 7 | 15 | 94 |
| [include/liblvgl/extra/libs/sjpg/tjpgdcnf.h](/include/liblvgl/extra/libs/sjpg/tjpgdcnf.h) | C++ | 5 | 22 | 7 | 34 |
| [include/liblvgl/extra/lv_extra.h](/include/liblvgl/extra/lv_extra.h) | C++ | 15 | 22 | 12 | 49 |
| [include/liblvgl/extra/others/fragment/lv_fragment.h](/include/liblvgl/extra/others/fragment/lv_fragment.h) | C++ | 67 | 221 | 52 | 340 |
| [include/liblvgl/extra/others/gridnav/lv_gridnav.h](/include/liblvgl/extra/others/gridnav/lv_gridnav.h) | C++ | 21 | 77 | 26 | 124 |
| [include/liblvgl/extra/others/ime/lv_ime_pinyin.h](/include/liblvgl/extra/others/ime/lv_ime_pinyin.h) | C++ | 52 | 64 | 30 | 146 |
| [include/liblvgl/extra/others/imgfont/lv_imgfont.h](/include/liblvgl/extra/others/imgfont/lv_imgfont.h) | C++ | 16 | 30 | 15 | 61 |
| [include/liblvgl/extra/others/lv_others.h](/include/liblvgl/extra/others/lv_others.h) | C++ | 16 | 19 | 10 | 45 |
| [include/liblvgl/extra/others/monkey/lv_monkey.h](/include/liblvgl/extra/others/monkey/lv_monkey.h) | C++ | 35 | 60 | 24 | 119 |
| [include/liblvgl/extra/others/msg/lv_msg.h](/include/liblvgl/extra/others/msg/lv_msg.h) | C++ | 30 | 70 | 25 | 125 |
| [include/liblvgl/extra/others/snapshot/lv_snapshot.h](/include/liblvgl/extra/others/snapshot/lv_snapshot.h) | C++ | 19 | 50 | 16 | 85 |
| [include/liblvgl/extra/themes/basic/lv_theme_basic.h](/include/liblvgl/extra/themes/basic/lv_theme_basic.h) | C++ | 14 | 28 | 14 | 56 |
| [include/liblvgl/extra/themes/default/lv_theme_default.h](/include/liblvgl/extra/themes/default/lv_theme_default.h) | C++ | 16 | 34 | 15 | 65 |
| [include/liblvgl/extra/themes/lv_themes.h](/include/liblvgl/extra/themes/lv_themes.h) | C++ | 12 | 19 | 10 | 41 |
| [include/liblvgl/extra/themes/mono/lv_theme_mono.h](/include/liblvgl/extra/themes/mono/lv_theme_mono.h) | C++ | 14 | 30 | 14 | 58 |
| [include/liblvgl/extra/widgets/animimg/lv_animimg.h](/include/liblvgl/extra/widgets/animimg/lv_animimg.h) | C++ | 31 | 50 | 23 | 104 |
| [include/liblvgl/extra/widgets/calendar/lv_calendar.h](/include/liblvgl/extra/widgets/calendar/lv_calendar.h) | C++ | 40 | 95 | 30 | 165 |
| [include/liblvgl/extra/widgets/calendar/lv_calendar_header_arrow.h](/include/liblvgl/extra/widgets/calendar/lv_calendar_header_arrow.h) | C++ | 14 | 24 | 12 | 50 |
| [include/liblvgl/extra/widgets/calendar/lv_calendar_header_dropdown.h](/include/liblvgl/extra/widgets/calendar/lv_calendar_header_dropdown.h) | C++ | 14 | 24 | 12 | 50 |
| [include/liblvgl/extra/widgets/chart/lv_chart.h](/include/liblvgl/extra/widgets/chart/lv_chart.h) | C++ | 132 | 266 | 63 | 461 |
| [include/liblvgl/extra/widgets/colorwheel/lv_colorwheel.h](/include/liblvgl/extra/widgets/colorwheel/lv_colorwheel.h) | C++ | 41 | 74 | 28 | 143 |
| [include/liblvgl/extra/widgets/imgbtn/lv_imgbtn.h](/include/liblvgl/extra/widgets/imgbtn/lv_imgbtn.h) | C++ | 36 | 71 | 25 | 132 |
| [include/liblvgl/extra/widgets/keyboard/lv_keyboard.h](/include/liblvgl/extra/widgets/keyboard/lv_keyboard.h) | C++ | 59 | 97 | 32 | 188 |
| [include/liblvgl/extra/widgets/led/lv_led.h](/include/liblvgl/extra/widgets/led/lv_led.h) | C++ | 34 | 58 | 25 | 117 |
| [include/liblvgl/extra/widgets/list/lv_list.h](/include/liblvgl/extra/widgets/list/lv_list.h) | C++ | 20 | 19 | 16 | 55 |
| [include/liblvgl/extra/widgets/lv_widgets.h](/include/liblvgl/extra/widgets/lv_widgets.h) | C++ | 28 | 19 | 10 | 57 |
| [include/liblvgl/extra/widgets/menu/lv_menu.h](/include/liblvgl/extra/widgets/menu/lv_menu.h) | C++ | 84 | 116 | 34 | 234 |
| [include/liblvgl/extra/widgets/meter/lv_meter.h](/include/liblvgl/extra/widgets/meter/lv_meter.h) | C++ | 100 | 130 | 38 | 268 |
| [include/liblvgl/extra/widgets/msgbox/lv_msgbox.h](/include/liblvgl/extra/widgets/msgbox/lv_msgbox.h) | C++ | 40 | 34 | 26 | 100 |
| [include/liblvgl/extra/widgets/span/lv_span.h](/include/liblvgl/extra/widgets/span/lv_span.h) | C++ | 65 | 140 | 41 | 246 |
| [include/liblvgl/extra/widgets/spinbox/lv_spinbox.h](/include/liblvgl/extra/widgets/spinbox/lv_spinbox.h) | C++ | 44 | 106 | 33 | 183 |
| [include/liblvgl/extra/widgets/spinner/lv_spinner.h](/include/liblvgl/extra/widgets/spinner/lv_spinner.h) | C++ | 17 | 20 | 14 | 51 |
| [include/liblvgl/extra/widgets/tabview/lv_tabview.h](/include/liblvgl/extra/widgets/tabview/lv_tabview.h) | C++ | 27 | 19 | 20 | 66 |
| [include/liblvgl/extra/widgets/tileview/lv_tileview.h](/include/liblvgl/extra/widgets/tileview/lv_tileview.h) | C++ | 27 | 27 | 19 | 73 |
| [include/liblvgl/extra/widgets/win/lv_win.h](/include/liblvgl/extra/widgets/win/lv_win.h) | C++ | 19 | 19 | 14 | 52 |
| [include/liblvgl/font/lv_font.h](/include/liblvgl/font/lv_font.h) | C++ | 170 | 62 | 56 | 288 |
| [include/liblvgl/font/lv_font_fmt_txt.h](/include/liblvgl/font/lv_font_fmt_txt.h) | C++ | 84 | 117 | 40 | 241 |
| [include/liblvgl/font/lv_font_loader.h](/include/liblvgl/font/lv_font_loader.h) | C++ | 11 | 19 | 11 | 41 |
| [include/liblvgl/font/lv_symbol_def.h](/include/liblvgl/font/lv_symbol_def.h) | C++ | 260 | 22 | 72 | 354 |
| [include/liblvgl/hal/lv_hal.h](/include/liblvgl/hal/lv_hal.h) | C++ | 14 | 25 | 10 | 49 |
| [include/liblvgl/hal/lv_hal_disp.h](/include/liblvgl/hal/lv_hal_disp.h) | C++ | 127 | 178 | 67 | 372 |
| [include/liblvgl/hal/lv_hal_indev.h](/include/liblvgl/hal/lv_hal_indev.h) | C++ | 106 | 86 | 48 | 240 |
| [include/liblvgl/hal/lv_hal_tick.h](/include/liblvgl/hal/lv_hal_tick.h) | C++ | 20 | 34 | 16 | 70 |
| [include/liblvgl/llemu.h](/include/liblvgl/llemu.h) | C++ | 52 | 356 | 31 | 439 |
| [include/liblvgl/llemu.hpp](/include/liblvgl/llemu.hpp) | C++ | 27 | 322 | 25 | 374 |
| [include/liblvgl/lv_api_map.h](/include/liblvgl/lv_api_map.h) | C++ | 32 | 37 | 20 | 89 |
| [include/liblvgl/lv_conf.h](/include/liblvgl/lv_conf.h) | C++ | 284 | 329 | 165 | 778 |
| [include/liblvgl/lv_conf.old.h](/include/liblvgl/lv_conf.old.h) | C++ | 184 | 95 | 63 | 342 |
| [include/liblvgl/lv_conf_checker.h](/include/liblvgl/lv_conf_checker.h) | C++ | 450 | 136 | 79 | 665 |
| [include/liblvgl/lv_conf_internal.h](/include/liblvgl/lv_conf_internal.h) | C++ | 2,006 | 285 | 179 | 2,470 |
| [include/liblvgl/lv_conf_kconfig.h](/include/liblvgl/lv_conf_kconfig.h) | C++ | 134 | 27 | 22 | 183 |
| [include/liblvgl/lvgl.h](/include/liblvgl/lvgl.h) | C++ | 65 | 49 | 25 | 139 |
| [include/liblvgl/misc/lv_anim.h](/include/liblvgl/misc/lv_anim.h) | C++ | 164 | 257 | 64 | 485 |
| [include/liblvgl/misc/lv_anim_timeline.h](/include/liblvgl/misc/lv_anim_timeline.h) | C++ | 21 | 62 | 21 | 104 |
| [include/liblvgl/misc/lv_area.h](/include/liblvgl/misc/lv_area.h) | C++ | 122 | 127 | 47 | 296 |
| [include/liblvgl/misc/lv_assert.h](/include/liblvgl/misc/lv_assert.h) | C++ | 42 | 22 | 16 | 80 |
| [include/liblvgl/misc/lv_async.h](/include/liblvgl/misc/lv_async.h) | C++ | 13 | 35 | 14 | 62 |
| [include/liblvgl/misc/lv_bidi.h](/include/liblvgl/misc/lv_bidi.h) | C++ | 41 | 80 | 21 | 142 |
| [include/liblvgl/misc/lv_color.h](/include/liblvgl/misc/lv_color.h) | C++ | 458 | 172 | 79 | 709 |
| [include/liblvgl/misc/lv_fs.h](/include/liblvgl/misc/lv_fs.h) | C++ | 90 | 133 | 40 | 263 |
| [include/liblvgl/misc/lv_gc.h](/include/liblvgl/misc/lv_gc.h) | C++ | 63 | 19 | 16 | 98 |
| [include/liblvgl/misc/lv_ll.h](/include/liblvgl/misc/lv_ll.h) | C++ | 34 | 105 | 29 | 168 |
| [include/liblvgl/misc/lv_log.h](/include/liblvgl/misc/lv_log.h) | C++ | 83 | 45 | 27 | 155 |
| [include/liblvgl/misc/lv_lru.h](/include/liblvgl/misc/lv_lru.h) | C++ | 42 | 24 | 22 | 88 |
| [include/liblvgl/misc/lv_math.h](/include/liblvgl/misc/lv_math.h) | C++ | 43 | 74 | 27 | 144 |
| [include/liblvgl/misc/lv_mem.h](/include/liblvgl/misc/lv_mem.h) | C++ | 79 | 123 | 42 | 244 |
| [include/liblvgl/misc/lv_printf.h](/include/liblvgl/misc/lv_printf.h) | C++ | 36 | 43 | 14 | 93 |
| [include/liblvgl/misc/lv_style.h](/include/liblvgl/misc/lv_style.h) | C++ | 327 | 194 | 72 | 593 |
| [include/liblvgl/misc/lv_style_gen.h](/include/liblvgl/misc/lv_style_gen.h) | C++ | 420 | 0 | 85 | 505 |
| [include/liblvgl/misc/lv_templ.h](/include/liblvgl/misc/lv_templ.h) | C++ | 9 | 19 | 10 | 38 |
| [include/liblvgl/misc/lv_timer.h](/include/liblvgl/misc/lv_timer.h) | C++ | 52 | 98 | 34 | 184 |
| [include/liblvgl/misc/lv_tlsf.h](/include/liblvgl/misc/lv_tlsf.h) | C++ | 36 | 45 | 15 | 96 |
| [include/liblvgl/misc/lv_txt.h](/include/liblvgl/misc/lv_txt.h) | C++ | 75 | 154 | 36 | 265 |
| [include/liblvgl/misc/lv_txt_ap.h](/include/liblvgl/misc/lv_txt_ap.h) | C++ | 19 | 19 | 12 | 50 |
| [include/liblvgl/misc/lv_types.h](/include/liblvgl/misc/lv_types.h) | C++ | 45 | 27 | 23 | 95 |
| [include/liblvgl/misc/lv_utils.h](/include/liblvgl/misc/lv_utils.h) | C++ | 12 | 36 | 11 | 59 |
| [include/liblvgl/widgets/lv_arc.h](/include/liblvgl/widgets/lv_arc.h) | C++ | 64 | 150 | 43 | 257 |
| [include/liblvgl/widgets/lv_bar.h](/include/liblvgl/widgets/lv_bar.h) | C++ | 53 | 82 | 30 | 165 |
| [include/liblvgl/widgets/lv_btn.h](/include/liblvgl/widgets/lv_btn.h) | C++ | 18 | 24 | 15 | 57 |
| [include/liblvgl/widgets/lv_btnmatrix.h](/include/liblvgl/widgets/lv_btnmatrix.h) | C++ | 61 | 129 | 36 | 226 |
| [include/liblvgl/widgets/lv_canvas.h](/include/liblvgl/widgets/lv_canvas.h) | C++ | 62 | 180 | 39 | 281 |
| [include/liblvgl/widgets/lv_checkbox.h](/include/liblvgl/widgets/lv_checkbox.h) | C++ | 26 | 51 | 21 | 98 |
| [include/liblvgl/widgets/lv_dropdown.h](/include/liblvgl/widgets/lv_dropdown.h) | C++ | 61 | 150 | 44 | 255 |
| [include/liblvgl/widgets/lv_img.h](/include/liblvgl/widgets/lv_img.h) | C++ | 56 | 139 | 40 | 235 |
| [include/liblvgl/widgets/lv_label.h](/include/liblvgl/widgets/lv_label.h) | C++ | 74 | 132 | 41 | 247 |
| [include/liblvgl/widgets/lv_line.h](/include/liblvgl/widgets/lv_line.h) | C++ | 24 | 49 | 21 | 94 |
| [include/liblvgl/widgets/lv_objx_templ.h](/include/liblvgl/widgets/lv_objx_templ.h) | C++ | 18 | 44 | 20 | 82 |
| [include/liblvgl/widgets/lv_roller.h](/include/liblvgl/widgets/lv_roller.h) | C++ | 39 | 70 | 30 | 139 |
| [include/liblvgl/widgets/lv_slider.h](/include/liblvgl/widgets/lv_slider.h) | C++ | 77 | 88 | 31 | 196 |
| [include/liblvgl/widgets/lv_switch.h](/include/liblvgl/widgets/lv_switch.h) | C++ | 20 | 25 | 17 | 62 |
| [include/liblvgl/widgets/lv_table.h](/include/liblvgl/widgets/lv_table.h) | C++ | 56 | 119 | 36 | 211 |
| [include/liblvgl/widgets/lv_textarea.h](/include/liblvgl/widgets/lv_textarea.h) | C++ | 85 | 216 | 58 | 359 |
| [include/main.h](/include/main.h) | C++ | 19 | 52 | 10 | 81 |
| [include/nlohmann/json.hpp](/include/nlohmann/json.hpp) | C++ | 17,452 | 4,342 | 2,972 | 24,766 |
| [include/nlohmann/json_fwd.hpp](/include/nlohmann/json_fwd.hpp) | C++ | 102 | 43 | 32 | 177 |
| [include/pros/abstract_motor.hpp](/include/pros/abstract_motor.hpp) | C++ | 122 | 949 | 74 | 1,145 |
| [include/pros/adi.h](/include/pros/adi.h) | C++ | 142 | 1,173 | 69 | 1,384 |
| [include/pros/adi.hpp](/include/pros/adi.hpp) | C++ | 169 | 1,770 | 108 | 2,047 |
| [include/pros/apix.h](/include/pros/apix.h) | C++ | 59 | 826 | 55 | 940 |
| [include/pros/colors.h](/include/pros/colors.h) | C++ | 163 | 32 | 10 | 205 |
| [include/pros/colors.hpp](/include/pros/colors.hpp) | C++ | 153 | 31 | 7 | 191 |
| [include/pros/device.h](/include/pros/device.h) | C++ | 28 | 53 | 11 | 92 |
| [include/pros/device.hpp](/include/pros/device.hpp) | C++ | 39 | 149 | 18 | 206 |
| [include/pros/distance.h](/include/pros/distance.h) | C++ | 19 | 129 | 13 | 161 |
| [include/pros/distance.hpp](/include/pros/distance.hpp) | C++ | 27 | 206 | 15 | 248 |
| [include/pros/error.h](/include/pros/error.h) | C++ | 9 | 25 | 9 | 43 |
| [include/pros/ext_adi.h](/include/pros/ext_adi.h) | C++ | 61 | 1,219 | 51 | 1,331 |
| [include/pros/gps.h](/include/pros/gps.h) | C++ | 65 | 779 | 41 | 885 |
| [include/pros/gps.hpp](/include/pros/gps.hpp) | C++ | 61 | 835 | 42 | 938 |
| [include/pros/imu.h](/include/pros/imu.h) | C++ | 87 | 838 | 50 | 975 |
| [include/pros/imu.hpp](/include/pros/imu.hpp) | C++ | 55 | 1,001 | 22 | 1,078 |
| [include/pros/link.h](/include/pros/link.h) | C++ | 47 | 352 | 23 | 422 |
| [include/pros/link.hpp](/include/pros/link.hpp) | C++ | 22 | 247 | 15 | 284 |
| [include/pros/llemu.h](/include/pros/llemu.h) | C++ | 20 | 27 | 8 | 55 |
| [include/pros/llemu.hpp](/include/pros/llemu.hpp) | C++ | 44 | 78 | 17 | 139 |
| [include/pros/misc.h](/include/pros/misc.h) | C++ | 150 | 637 | 48 | 835 |
| [include/pros/misc.hpp](/include/pros/misc.hpp) | C++ | 59 | 492 | 27 | 578 |
| [include/pros/motor_group.hpp](/include/pros/motor_group.hpp) | C++ | 108 | 2,210 | 60 | 2,378 |
| [include/pros/motors.h](/include/pros/motors.h) | C++ | 192 | 1,082 | 68 | 1,342 |
| [include/pros/motors.hpp](/include/pros/motors.hpp) | C++ | 102 | 2,236 | 89 | 2,427 |
| [include/pros/optical.h](/include/pros/optical.h) | C++ | 60 | 386 | 28 | 474 |
| [include/pros/optical.hpp](/include/pros/optical.hpp) | C++ | 35 | 380 | 25 | 440 |
| [include/pros/rotation.h](/include/pros/rotation.h) | C++ | 27 | 343 | 21 | 391 |
| [include/pros/rotation.hpp](/include/pros/rotation.hpp) | C++ | 31 | 342 | 22 | 395 |
| [include/pros/rtos.h](/include/pros/rtos.h) | C++ | 100 | 947 | 62 | 1,109 |
| [include/pros/rtos.hpp](/include/pros/rtos.hpp) | C++ | 151 | 1,371 | 59 | 1,581 |
| [include/pros/screen.h](/include/pros/screen.h) | C++ | 88 | 658 | 46 | 792 |
| [include/pros/screen.hpp](/include/pros/screen.hpp) | C++ | 54 | 624 | 40 | 718 |
| [include/pros/serial.h](/include/pros/serial.h) | C++ | 25 | 365 | 20 | 410 |
| [include/pros/serial.hpp](/include/pros/serial.hpp) | C++ | 26 | 301 | 18 | 345 |
| [include/pros/vision.h](/include/pros/vision.h) | C++ | 95 | 713 | 44 | 852 |
| [include/pros/vision.hpp](/include/pros/vision.hpp) | C++ | 51 | 707 | 30 | 788 |
| [include/robodash/api.h](/include/robodash/api.h) | C++ | 24 | 8 | 11 | 43 |
| [include/robodash/apix.h](/include/robodash/apix.h) | C++ | 5 | 13 | 2 | 20 |
| [include/robodash/core.h](/include/robodash/core.h) | C++ | 22 | 64 | 16 | 102 |
| [include/robodash/impl/assets.h](/include/robodash/impl/assets.h) | C++ | 10 | 5 | 5 | 20 |
| [include/robodash/impl/filesystem.h](/include/robodash/impl/filesystem.h) | C++ | 8 | 5 | 5 | 18 |
| [include/robodash/impl/styles.h](/include/robodash/impl/styles.h) | C++ | 51 | 12 | 25 | 88 |
| [include/robodash/views/console.hpp](/include/robodash/views/console.hpp) | C++ | 25 | 48 | 14 | 87 |
| [include/robodash/views/image.hpp](/include/robodash/views/image.hpp) | C++ | 13 | 41 | 11 | 65 |
| [include/robodash/views/selector.hpp](/include/robodash/views/selector.hpp) | C++ | 31 | 38 | 17 | 86 |
| [include/usr/autons.h](/include/usr/autons.h) | C++ | 23 | 2 | 1 | 26 |
| [include/usr/logging.h](/include/usr/logging.h) | C++ | 32 | 1 | 14 | 47 |
| [include/usr/robot.h](/include/usr/robot.h) | C++ | 99 | 5 | 12 | 116 |
| [include/usr/utils.h](/include/usr/utils.h) | C++ | 5 | 0 | 2 | 7 |
| [src/autons.cpp](/src/autons.cpp) | C++ | 234 | 40 | 12 | 286 |
| [src/main.cpp](/src/main.cpp) | C++ | 55 | 65 | 11 | 131 |
| [src/robotConfig/Inits.cpp](/src/robotConfig/Inits.cpp) | C++ | 44 | 0 | 10 | 54 |
| [src/robotConfig/Tuning.cpp](/src/robotConfig/Tuning.cpp) | C++ | 131 | 0 | 12 | 143 |
| [src/robotConfig/globals.cpp](/src/robotConfig/globals.cpp) | C++ | 89 | 3 | 10 | 102 |
| [src/robotConfig/robotActions.cpp](/src/robotConfig/robotActions.cpp) | C++ | 90 | 0 | 6 | 96 |
| [src/utils.cpp](/src/utils.cpp) | C++ | 22 | 0 | 9 | 31 |

[Summary](results.md) / Details / [Diff Summary](diff.md) / [Diff Details](diff-details.md)