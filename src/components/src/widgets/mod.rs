use iced_native::{
    event::{self, Event},
    layout, renderer, text, Clipboard, Element, Hasher, Layout, Length, Point, Rectangle, Size,
    Text,
};
use std::marker::PhantomData;

type WRenderer = crate::WRenderer;
// trait Widget<Message> = crate::Widget<Message>;

use iced_native::widget::Widget;

pub struct EventWidget<W, F>
where
    F: FnMut(&mut W, &Event) -> bool,
{
    w: W,
    on_event_fn: F,
}

impl<Message, W, F> Widget<Message, WRenderer> for EventWidget<W, F>
where
    W: Widget<Message, WRenderer>,
    F: FnMut(&mut W, &Event) -> bool,
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
        renderer: &WRenderer,
        clipboard: &mut dyn Clipboard,
        messages: &mut Vec<Message>,
    ) -> event::Status {
        if (self.on_event_fn)(&mut self.w, &event) {
            event::Status::Captured
        } else {
            event::Status::Ignored
        }

        // Widget::<Message, WRenderer>::on_event(
        //     self,
        //     event,
        //     layout,
        //     cursor_position,
        //     renderer,
        //     clipboard,
        //     messages,
        // );

        // event::Status::Captured
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

impl<W, F> EventWidget<W, F>
where
    F: FnMut(&mut W, &Event) -> bool,
{
    pub fn new(w: W, f: F) -> Self {
        Self {
            w: w,
            on_event_fn: f,
        }
    }
}

impl<'a, Message, W: 'a, F: 'a> From<EventWidget<W, F>> for Element<'a, Message, WRenderer>
where
    W: Widget<Message, WRenderer>,
    F: FnMut(&mut W, &Event) -> bool,
{
    fn from(w: EventWidget<W, F>) -> Element<'a, Message, WRenderer> {
        Element::new(w)
    }
}
