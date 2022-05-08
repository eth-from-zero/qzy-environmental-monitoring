#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;

fn main() {
    let view = TableView::new();

    view.on_right_click_on_the_item(|index, x, y| {
        println!("index={}, x={}, y={}", index, x, y);
    });

    view.on_right_click_on_the_view(|index, x, y, t| {
        println!("view: index={}, x={}, y={}, text={}", index, x, y, t);
    });

    view.on_menu_on_clicked(|index, value| {
        println!("menu index = {}, value = {}", index, value);
    });

    view.run();
}
