#![feature(trait_alias)]

mod tableview;

trait Widget<Message> = iced_native::widget::Widget<Message, iced_wgpu::Renderer>;

type WgpuRenderer = iced_wgpu::Renderer;
