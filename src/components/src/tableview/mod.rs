use iced_native::{
    event::{self, Event},
    layout, renderer, text, Clipboard, Element, Hasher, Layout, Length, Point, Rectangle, Size,
    Text,
};
use std::marker::PhantomData;

type WRenderer = crate::WgpuRenderer;
// trait Widget<Message> = crate::Widget<Message>;

use iced_native::widget::Widget;

struct TableWidget<W> {
    w: W,
}

impl<Message, W> Widget<Message, WRenderer> for TableWidget<W>
where
    W: Widget<Message, WRenderer>,
{
    fn width(&self) -> Length {
        Widget::<Message, WRenderer>::width(&self.w)
    }

    fn height(&self) -> Length {
        Widget::<Message, WRenderer>::height(&self.w)
    }

    fn layout(&self, renderer: &WRenderer, limits: &layout::Limits) -> layout::Node {
        Widget::<Message, WRenderer>::layout(&self.w, renderer, limits)
    }

    fn on_event(
        &mut self,
        event: Event,
        layout: Layout<'_>,
        cursor_position: Point,
        _renderer: &WRenderer,
        _clipboard: &mut dyn Clipboard,
        _messages: &mut Vec<Message>,
    ) -> event::Status {
        event::Status::Captured
    }

    fn draw(
        &self,
        renderer: &mut WRenderer,
        defaults: &<WRenderer as iced_native::renderer::Renderer>::Defaults,
        layout: Layout<'_>,
        cursor_position: Point,
        viewport: &Rectangle,
    ) -> <WRenderer as iced_native::renderer::Renderer>::Output {
        Widget::<Message, WRenderer>::draw(
            &self.w,
            renderer,
            defaults,
            layout,
            cursor_position,
            viewport,
        )
    }

    fn hash_layout(&self, state: &mut Hasher) {
        Widget::<Message, WRenderer>::hash_layout(&self.w, state);
    }
}

impl<W> TableWidget<W> {
    pub fn new(w: W) -> Self {
        Self { w: w }
    }
}

impl<'a, Message, W: 'a> From<TableWidget<W>> for Element<'a, Message, WRenderer>
where
    W: Widget<Message, WRenderer>,
{
    fn from(w: TableWidget<W>) -> Element<'a, Message, WRenderer> {
        Element::new(w)
    }
}

use iced::{
    button, scrollable, Button, Column, Container, ProgressBar, Radio, Row, Rule, Sandbox,
    Scrollable, Settings, Space,
};

struct TableView<Message> {
    scrollable: iced::scrollable::State,
    _msg: PhantomData<Message>,
}

impl<Message> TableView<Message>
where
    Message: Send + std::fmt::Debug,
{
    fn new() -> Self {
        TableView {
            scrollable: scrollable::State::new(),
            _msg: PhantomData,
        }
    }

    fn build_view<'a, W: 'a>(
        &'a mut self,
        children: impl IntoIterator<Item = TableWidget<W>>,
    ) -> iced::Element<Message>
    where
        // E: Into<Element<'a, Message, WRenderer>>,
        W: Widget<Message, WRenderer>,
        // E: TableWidget<W>,
    {
        let scrollable_row = Row::with_children(vec![{
            let mut scrollable = Scrollable::new(&mut self.scrollable)
                // .padding(10)
                // .spacing(10)
                .width(Length::Fill)
                .height(Length::Fill);
            for child in children.into_iter() {
                scrollable = scrollable.push(child);
            }

            Column::new()
                .width(Length::Fill)
                .height(Length::Units(10))
                // .spacing(10)
                .push(
                    Container::new(scrollable)
                        .width(Length::Fill)
                        .height(Length::Fill),
                )
                .into()
        }])
        // .spacing(20)
        .width(Length::Fill)
        .height(Length::Fill);

        let content = Column::new().spacing(20).padding(20).push(scrollable_row);

        Container::new(content)
            .width(Length::Fill)
            .height(Length::Fill)
            .center_x()
            .center_y()
            .into()
    }
}

#[cfg(test)]
mod test {
    use super::*;

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

        fn view(&mut self) -> Element<Message, WRenderer> {
            self.table_view
                .build_view(vec![TableWidget::new(Text::new("hello"))])
        }
    }
}
