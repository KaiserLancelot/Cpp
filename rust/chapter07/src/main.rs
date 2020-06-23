use chapter07::hosting;

mod module {
    pub fn fun() {}
}

fn main() {
    hosting::add_to_waitlist();
    crate::module::fun();
}
