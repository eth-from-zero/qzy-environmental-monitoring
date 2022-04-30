#![feature(trait_alias)]

mod tableview;
mod widgets;

trait Widget<Message> = iced_native::widget::Widget<Message, iced_wgpu::Renderer>;

pub type WRenderer = iced_wgpu::Renderer;

pub use tableview::{TableView, TableWidget};
