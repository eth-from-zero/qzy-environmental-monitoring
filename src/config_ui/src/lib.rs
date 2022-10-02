#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

pub mod ui;

#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;
