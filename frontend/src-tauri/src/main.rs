// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]
use std::process::Command;
use std::thread;

fn launch_backend() {
    let mut path = String::from("../../backend/backend");

    if cfg!(target_os = "windows") {
        path.push_str(".exe");
    }

    thread::Builder::new().name("osmium-backend".to_string()).spawn(move || {
        Command::new(&path)
            .spawn()
            .expect("Failed to execute backend binary");
    }).expect("Failed to spawn backend thread");
}

// Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
fn main() {
    tauri::Builder::default()
        .setup(|_| Ok(launch_backend()))
        .invoke_handler(tauri::generate_handler![/*greet*/])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
