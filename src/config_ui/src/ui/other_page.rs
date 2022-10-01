use config_ui::Main;

pub fn init(win: &Main) {
    let win_weak = win.as_weak();
    win.on_other_page_data_query_and_table_report_dialog_to_single_right_clicked(move || {
        let win = win_weak.unwrap();

        win.get_other_page_data_query_and_table_report_dialog_left_rows();
    });
}
