#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use crate::ComponentHandle;
// use crate::DeviceEditDialogE;

#[allow(clippy::all)]
mod generated_code {
    slint::include_modules!();
}
pub use generated_code::*;

pub struct DeviceUI {
    dialog: DeviceEditDialogE,
}

impl DeviceUI {
    pub fn new() -> Self {
        let dialog = DeviceEditDialogE::new();
        dialog.hide();
        Self { dialog: dialog }
    }

    pub fn show_edit_dialog(&self) {
        self.dialog.show();
    }
}
