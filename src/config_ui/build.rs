fn main() {
    slint_build::compile("ui/main.slint").unwrap();
    // slint_build::compile("ui/testmain.slint").unwrap();
    // slint_build::compile_with_config(
    //     "ui/main.slint",
    //     slint_build::CompilerConfiguration::new()
    //         .with_include_paths(vec!["ui/main.slint".into(), "ui/testmain.slint".into()]),
    // )
    // .unwrap();
}
