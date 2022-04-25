use iced_native::{
    event::{self, Event},
    layout, renderer, text, Clipboard, Element, Hasher, Layout, Length, Point, Rectangle, Size,
    Text,
};
use std::marker::PhantomData;

type WRenderer = crate::WgpuRenderer;
// trait Widget<Message> = crate::Widget<Message>;

use iced_native::widget::Widget;

struct TableWidget<W, F>
where
    F: FnMut(&W, &Event),
{
    w: W,
    on_event: F,
}

impl<Message, W, F> Widget<Message, WRenderer> for TableWidget<W, F>
where
    W: Widget<Message, WRenderer>,
    F: FnMut(&W, &Event),
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

impl<W, F> TableWidget<W, F>
where
    F: FnMut(&W, &Event),
{
    pub fn new(w: W, f: F) -> Self {
        Self { w: w, on_event: f }
    }
}

impl<'a, Message, W: 'a, F: 'a> From<TableWidget<W, F>> for Element<'a, Message, WRenderer>
where
    W: Widget<Message, WRenderer>,
    F: FnMut(&W, &Event),
{
    fn from(w: TableWidget<W, F>) -> Element<'a, Message, WRenderer> {
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

    fn build_view<'a, W: 'a, F: 'a>(
        &'a mut self,
        children: impl IntoIterator<Item = TableWidget<W, F>>,
    ) -> iced::Element<Message>
    where
        // E: Into<Element<'a, Message, WRenderer>>,
        W: Widget<Message, WRenderer>,
        F: FnMut(&W, &Event),
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
