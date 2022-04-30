use iced::{button, Button, Column, Element, Sandbox, Settings, Text};

use components::{TableView, TableWidget, WRenderer};

pub struct TestView {
    table_view: TableView<Message>,
}

#[derive(Debug, Clone)]
pub enum Message {}

impl Sandbox for TestView {
    type Message = Message;

    fn new() -> Self {
        Self {
            table_view: TableView::new(),
        }
    }

    fn title(&self) -> String {
        String::from("TableView")
    }

    fn update(&mut self, message: Message) {}

    fn view(&mut self) -> Element<Message> {
        self.table_view
            .build_view(vec![TableWidget::new(Text::new("hello"), |w, e| {
                println!("{:?}", e);
            })])
    }
}

fn main() {
    TestView::run(Settings::default());
}
