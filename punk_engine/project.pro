#-------------------------------------------------
#
# Project created by QtCreator 2011-07-15T14:13:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = project
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += \
    system/window.h \
    system/types.h \
    system/timer.h \
    system/thread.h \
    system/system.h \
    system/string.h \
    system/process.h \
    system/object.h \
    system/monitor_scope.h \
    system/monitor.h \
    system/keyboard.h \
    system/folder.h \
    system/exception.h \
    system/event_manager.h \
    system/environment.h \
    system/console.h \
    system/clock.h \
    system/buffer.h \
    system/binary_file.h \
    system/allocator.h \
    punk_engine.h \
    DP5.h \
    common/simple_container.h \
    common/logger.h \
    common/geometry.h \
    common/common.h \
    common/camera.h \
    common/attachable_object.h \
    driver/video/driver.h \
    driver/video/opengl/vbo.h \
    driver/video/opengl/texture2d_object.h \
    driver/video/opengl/standard_shaders.h \
    driver/video/opengl/shader_program.h \
    driver/video/opengl/os.h \
    driver/video/opengl/material.h \
    driver/video/opengl/light_manager.h \
    driver/video/opengl/light.h \
    driver/video/opengl/glsl_program.h \
    driver/video/opengl/frame_buffer_with_depth.h \
    driver/video/opengl/frame_buffer.h \
    driver/video/opengl/extensions.h \
    driver/video/opengl/driver_parameters.h \
    driver/video/opengl/driver.h \
    driver/video/opengl/camera.h \
    driver/video/opengl/linux/driver_parameters_linux.h \
    driver/video/opengl/nvtristrip/vertex_cache.h \
    driver/video/opengl/nvtristrip/nv_tri_strip_objects.h \
    driver/video/opengl/nvtristrip/nv_tri_strip.h \
    driver/video/opengl/win32/driver_parameters_win32.h \
    generator/generator.h \
    gui/widget.h \
    gui/watcher.h \
    gui/vertical_slider.h \
    gui/vertical_scrollbar.h \
    gui/static_text_area.h \
    gui/manager.h \
    gui/list_box.h \
    gui/int_watcher.h \
    gui/horizontal_slider.h \
    gui/gui.h \
    gui/edit_box.h \
    gui/console.h \
    gui/button.h \
    images/bmp/bmp.h \
    images/dds/nv_dds.h \
    images/jpeg/transupp.h \
    images/jpeg/jversion.h \
    images/jpeg/jpeglib.h \
    images/jpeg/jpegint.h \
    images/jpeg/jmorecfg.h \
    images/jpeg/jmemsys.h \
    images/jpeg/jinclude.h \
    images/jpeg/jerror.h \
    images/jpeg/jdct.h \
    images/jpeg/jconfig.h \
    images/jpeg/cdjpeg.h \
    images/jpeg/cderror.h \
    images/png/pngpriv.h \
    images/png/pngconf.h \
    images/png/png.h \
    images/tga/tga.h \
    images/zlib/zutil.h \
    images/zlib/zlib.h \
    images/zlib/zconf.h \
    images/zlib/trees.h \
    images/zlib/inftrees.h \
    images/zlib/inflate.h \
    images/zlib/inffixed.h \
    images/zlib/inffast.h \
    images/zlib/gzguts.h \
    images/zlib/deflate.h \
    images/zlib/crc32.h \
    images/texture.h \
    images/surface.h \
    images/image_loader.h \
    images/image_file.h \
    images/formats.h \
    math/vec4.h \
    math/vec3.h \
    math/vec2.h \
    math/type.h \
    math/Triangle3D.h \
    math/Triangle2D.h \
    math/Sphere.h \
    math/quat.h \
    math/Quad.h \
    math/plane.h \
    math/Matrix4x4.h \
    math/math.h \
    math/mat4.h \
    math/mat3.h \
    math/mat2.h \
    math/low_level_math.h \
    math/Line3D.h \
    math/Line2D.h \
    math/line.h \
    math/interpolation.h \
    math/helper.h \
    math/functions.h \
    math/frustum.h \
    math/complex.h \
    math/bounding_box.h \
    render/vertex_array_object.h \
    render/terrain_render.h \
    render/terrain.h \
    render/solid_render.h \
    render/render_state.h \
    render/render_parameters.h \
    render/render_element.h \
    render/render.h \
    render/pipeline.h \
    render/per_vertex_render.h \
    render/font_builder.h \
    render/advanced_static_mesh.h \
    render/abstract_render.h \
    render/3DElement.h \
    render/3d_line_render.h \
    render/2d/2d_text_area_render.h \
    render/2d/2d_quad_render.h \
    render/2d/2d_line_render.h \
    shaders/shader_manager.h \
    system/win32/window_win32.h \
    system/win32/types_win32.h \
    system/win32/timer_win32.h \
    system/win32/thread_win32.h \
    system/win32/text_file_win32.h \
    system/win32/string_win32.h \
    system/win32/static_string.h \
    system/win32/static_array.h \
    system/win32/process_win32.h \
    system/win32/monitor_win32.h \
    system/win32/keyboard_win32.h \
    system/win32/folder_win32.h \
    system/win32/environment_win32.h \
    system/win32/console_win32.h \
    system/win32/clock_win32.h \
    system/win32/buffer_win32.h \
    system/win32/binary_file_win32.h \
    system/win32/allocator_win32.h \
    system/linux/window_linux.h \
    system/linux/types_linux.h \
    system/linux/timer_linux.h \
    system/linux/text_file_linux.h \
    system/linux/monitor_linux.h \
    system/linux/folder_linux.h \
    system/linux/clock_linux.h \
    system/events/window_resize_event.h \
    system/events/unfocused.h \
    system/events/mouse_wheel_event.h \
    system/events/mouse_right_button_up.h \
    system/events/mouse_right_button_down.h \
    system/events/mouse_move_event.h \
    system/events/mouse_middle_button_up.h \
    system/events/mouse_middle_button_down.h \
    system/events/mouse_left_button_up.h \
    system/events/mouse_left_button_down.h \
    system/events/mouse_leave.h \
    system/events/mouse_enter.h \
    system/events/key_wchar_event.h \
    system/events/key_up_event.h \
    system/events/key_down_event.h \
    system/events/key_char_event.h \
    system/events/idle_event.h \
    system/events/focused.h \
    system/events/events.h \
    system/events/event_type.h \
    system/events/event.h \
    translator/module.h \
    translator/console_interpretator.h \
    translator/echo_module/echo_module.h \
    types/types.h \
    types/string.h \
    xml/tinyxml.h \
    xml/tinystr.h \
    common/factory.h \
    common/singletone.h

SOURCES += \
    system/string.cpp \
    system/object.cpp \
    system/event_manager.cpp \
    system/clock.cpp \
    system/allocator.cpp \
    unity_build.cpp \
    DP5Geometry.cpp \
    DP5.cpp \
    common/simple_container.cpp \
    common/logger.cpp \
    common/geometry.cpp \
    common/camera.cpp \
    common/attachable_object.cpp \
    driver/video/opengl/vbo.cpp \
    driver/video/opengl/texture2d_object.cpp \
    driver/video/opengl/material.cpp \
    driver/video/opengl/light_manager.cpp \
    driver/video/opengl/light.cpp \
    driver/video/opengl/glsl_program.cpp \
    driver/video/opengl/frame_buffer_with_depth.cpp \
    driver/video/opengl/frame_buffer.cpp \
    driver/video/opengl/extensions.cpp \
    driver/video/opengl/camera.cpp \
    driver/video/opengl/linux/video_driver_linux.cpp \
    driver/video/opengl/linux/driver_parameters_linux.cpp \
    driver/video/opengl/nvtristrip/vertex_cache.cpp \
    driver/video/opengl/nvtristrip/nv_tri_strip_objects.cpp \
    driver/video/opengl/nvtristrip/nv_tri_strip.cpp \
    driver/video/opengl/win32/video_driver_win32.cpp \
    driver/video/opengl/win32/driver_parameters_win32.cpp \
    generator/generator.cpp \
    gui/widget.cpp \
    gui/vertical_slider.cpp \
    gui/vertical_scrollbar.cpp \
    gui/static_text_area.cpp \
    gui/manager.cpp \
    gui/main.cpp \
    gui/list_box.cpp \
    gui/int_watcher.cpp \
    gui/horizontal_slider.cpp \
    gui/edit_box.cpp \
    gui/console.cpp \
    gui/button.cpp \
    images/jpeg/wrtarga.c \
    images/jpeg/wrrle.c \
    images/jpeg/wrppm.c \
    images/jpeg/wrgif.c \
    images/jpeg/wrbmp.c \
    images/jpeg/transupp.c \
    images/jpeg/rdtarga.c \
    images/jpeg/rdswitch.c \
    images/jpeg/rdrle.c \
    images/jpeg/rdppm.c \
    images/jpeg/rdgif.c \
    images/jpeg/rdcolmap.c \
    images/jpeg/rdbmp.c \
    images/jpeg/jutils.c \
    images/jpeg/jquant2.c \
    images/jpeg/jquant1.c \
    images/jpeg/jmemnobs.c \
    images/jpeg/jmemmgr.c \
    images/jpeg/jidctint.c \
    images/jpeg/jidctfst.c \
    images/jpeg/jidctflt.c \
    images/jpeg/jfdctint.c \
    images/jpeg/jfdctfst.c \
    images/jpeg/jfdctflt.c \
    images/jpeg/jerror.c \
    images/jpeg/jdtrans.c \
    images/jpeg/jdsample.c \
    images/jpeg/jdpostct.c \
    images/jpeg/jdmerge.c \
    images/jpeg/jdmaster.c \
    images/jpeg/jdmarker.c \
    images/jpeg/jdmainct.c \
    images/jpeg/jdinput.c \
    images/jpeg/jdhuff.c \
    images/jpeg/jddctmgr.c \
    images/jpeg/jdcolor.c \
    images/jpeg/jdcoefct.c \
    images/jpeg/jdatasrc.c \
    images/jpeg/jdatadst.c \
    images/jpeg/jdarith.c \
    images/jpeg/jdapistd.c \
    images/jpeg/jdapimin.c \
    images/jpeg/jctrans.c \
    images/jpeg/jcsample.c \
    images/jpeg/jcprepct.c \
    images/jpeg/jcparam.c \
    images/jpeg/jcomapi.c \
    images/jpeg/jcmaster.c \
    images/jpeg/jcmarker.c \
    images/jpeg/jcmainct.c \
    images/jpeg/jcinit.c \
    images/jpeg/jchuff.c \
    images/jpeg/jcdctmgr.c \
    images/jpeg/jccolor.c \
    images/jpeg/jccoefct.c \
    images/jpeg/jcarith.c \
    images/jpeg/jcapistd.c \
    images/jpeg/jcapimin.c \
    images/jpeg/jaricom.c \
    images/jpeg/cdjpeg.c \
    images/png/pngwutil.c \
    images/png/pngwtran.c \
    images/png/pngwrite.c \
    images/png/pngwio.c \
    images/png/pngtrans.c \
    images/png/pngset.c \
    images/png/pngrutil.c \
    images/png/pngrtran.c \
    images/png/pngrio.c \
    images/png/pngread.c \
    images/png/pngpread.c \
    images/png/pngmem.c \
    images/png/pngget.c \
    images/png/pngerror.c \
    images/png/png.c \
    images/png/new_push_process_row.c \
    images/png/example.c \
    images/tga/tga.cpp \
    images/tga/tga.cpp \
    images/zlib/zutil.c \
    images/zlib/uncompr.c \
    images/zlib/trees.c \
    images/zlib/inftrees.c \
    images/zlib/inflate.c \
    images/zlib/inffast.c \
    images/zlib/infback.c \
    images/zlib/gzwrite.c \
    images/zlib/gzread.c \
    images/zlib/gzlib.c \
    images/zlib/gzclose.c \
    images/zlib/deflate.c \
    images/zlib/crc32.c \
    images/zlib/compress.c \
    images/zlib/adler32.c \
    images/texture.cpp \
    images/surface.cpp \
    images/image_loader.cpp \
    images/image_file.cpp \
    math/Vector3.cpp \
    math/Triangle3D.cpp \
    math/Triangle2D.cpp \
    math/plane.cpp \
    math/Line3D.cpp \
    math/Line2D.cpp \
    math/line.cpp \
    math/helper.cpp \
    math/functions.cpp \
    math/frustum.cpp \
    math/bounding_box.cpp \
    render/vertex_array_object.cpp \
    render/terrain_render.cpp \
    render/solid_render.cpp \
    render/slider.cpp \
    render/render_state.cpp \
    render/render_element.cpp \
    render/render.cpp \
    render/pipeline.cpp \
    render/per_vertex_render.cpp \
    render/font_builder.cpp \
    render/advanced_static_mesh.cpp \
    render/3d_line_render.cpp \
    render/2d/2d_text_area_render.cpp \
    render/2d/2d_quad_render.cpp \
    render/2d/2d_line_render.cpp \
    shaders/shader_manager.cpp \
    system/win32/window_win32.cpp \
    system/win32/timer_win32.cpp \
    system/win32/thread_win32.cpp \
    system/win32/text_file_win32.cpp \
    system/win32/string_win32.cpp \
    system/win32/process_win32.cpp \
    system/win32/keyboard_win32.cpp \
    system/win32/folder_win32.cpp \
    system/win32/environment_win32.cpp \
    system/win32/console_win32.cpp \
    system/win32/clock_win32.cpp \
    system/win32/buffer_win32.cpp \
    system/win32/binary_file_win32.cpp \
    system/win32/allocator_win32.cpp \
    system/linux/window_linux.cpp \
    system/linux/timer_linux.cpp \
    system/linux/text_file_linux.cpp \
    system/linux/folder_linux.cpp \
    system/linux/clock_linux.cpp \
    system/events/window_resize_event.cpp \
    system/events/unfocused.cpp \
    system/events/mouse_wheel_event.cpp \
    system/events/mouse_right_button_up.cpp \
    system/events/mouse_right_button_down.cpp \
    system/events/mouse_move_event.cpp \
    system/events/mouse_middle_button_up.cpp \
    system/events/mouse_middle_button_down.cpp \
    system/events/mouse_left_button_up.cpp \
    system/events/mouse_left_button_down.cpp \
    system/events/mouse_leave.cpp \
    system/events/mouse_enter.cpp \
    system/events/key_wchar_event.cpp \
    system/events/key_up_event.cpp \
    system/events/key_down_event.cpp \
    system/events/key_char_event.cpp \
    system/events/idle_event.cpp \
    system/events/focused.cpp \
    system/events/events.cpp \
    translator/console_interpretator.cpp \
    translator/echo_module/echo_module.cpp \
    xml/tinyxmlparser.cpp \
    xml/tinyxmlerror.cpp \
    xml/tinyxml.cpp \
    xml/tinystr.cpp

OTHER_FILES += \
    resource.rct \
    project.pro.user \
    project.pro \
    .DP5.h.swp \
    blender/punk_mesh_exporter.py \
    blender/punk_mesh_exporter.pm \
    blender/punk_exporter_2_57.py \
    blender/punk_exporter_2_57 \
    blender/punk_exporter.py \
    driver/video/opengl/material.txt \
    driver/video/opengl/nvtristrip/README.txt \
    math/Vector2.cppC \
    shaders/textured_2d_330.vert \
    shaders/textured_2d_330.frag \
    shaders/terrain_330.vert \
    shaders/terrain_330.frag \
    shaders/terrain_330 - Copy.vert \
    shaders/terrain_330 - Copy.frag \
    shaders/StandardShaders.rfx \
    shaders/StandardShaders.fx \
    shaders/StandardShaders.cg \
    shaders/solid_color_3d_330.vert \
    shaders/solid_color_3d_330.frag \
    shaders/solid_color_2d_330.vert \
    shaders/solid_color_2d_330.frag \
    shaders/shaders.ini \
    shaders/per_vertex_lighting_330.vert \
    shaders/per_vertex_lighting_330.frag \
    shaders/lumina_shaders \
    shaders/line_3d_330.vert \
    shaders/line_3d_330.frag \
    shaders/line_2d_330.vert \
    shaders/line_2d_330.frag \
    shaders/draw_normals.vert \
    shaders/draw_normals.frag
