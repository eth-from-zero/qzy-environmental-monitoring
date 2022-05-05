#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;

fn main() {
    let m = Menu::new();

    m.run();
}
