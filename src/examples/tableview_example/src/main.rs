#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;

use slint::{Model, VecModel};

fn main() {
    let view = TableView::new();

    view.on_right_click_on_the_view(|index, x, y, t| {
        println!("view: index={}, x={}, y={}, text={}", index, x, y, t);
    });

    view.on_menu_on_clicked(|index, value| {
        println!("menu index = {}, value = {}", index, value);
    });

    let v_clone = view.as_weak();

    view.on_right_click_view(move |mx, my| {
        let v = v_clone.unwrap();
        let current_index = my / v.get_item_height();
        let rows = v.get_rows();
        rows.as_any().downcast_ref::<VecModel<Row>>().unwrap();
        println!(
            "current_index={}, mx={}, my={}, item-text={}",
            current_index,
            mx,
            my,
            rows.row_data(current_index as usize).unwrap().text
        );
    });

    view.run();
}
