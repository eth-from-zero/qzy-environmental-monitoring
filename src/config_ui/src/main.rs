#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;

fn main() {
    let win = Main::new();

    win.run();
}
