--绘制坐标系网格

require("gdi");

_G.print = window.log_txt;


window_width = window_width or 800;
window_height = window_height or 800;

window.set_log_back_color(0xCC000000);
window.set_log_edge_color(0xFFCCCCCC);

grid_width = 40;
grid_height = 30;

--window.log_clear();

function window.on_size(w, h)
    window_width = w;
    window_height = h;
    window.set_text_box(w / 4, h * 3 / 4, w / 2, h / 2);
end

ellipse_size = 100;

window.set_back_color(0xff333333);
function window.on_draw()
    --window.set_smoothing_mode(SmoothingMode.SmoothingModeHighSpeed);
    window.set_line_width(1);
    window.set_line_color(0xff337733);
    window.set_dash_style(DashStyle.DashStyleDashDotDot);

    for y = 0, window_height // grid_height do
        window.draw_line({x=0,y=grid_height*y}, {x=window_width, y=grid_height*y});
    end

    for x = 0, window_width // grid_width do
        window.draw_line({x=grid_width*x,y=0}, {x=grid_width*x, y=window_height});
    end

    if ellipse_point and ellipse_size > 0 then
        window.set_fill_color(0x33337733);
        window.fill_ellipse(ellipse_point.x - ellipse_size / 2, ellipse_point.y + ellipse_size / 2, ellipse_size, ellipse_size);
    end
end

function window.on_timer()
    if ellipse_size > 0 then
        ellipse_size = ellipse_size * 0.99;
    end
end

function window.on_lbutton_up(x, y)
    ellipse_point = {x=x, y=y};
    ellipse_size = 100;
end


