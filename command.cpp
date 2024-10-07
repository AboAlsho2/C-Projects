#include "command.hpp"


void Command::open_google() {
    _popen("start https://www.google.com", "r");
}

void Command::open_youtube() {
    _popen("start https://www.youtube.com", "r");
}

void Command::open_github() {
    _popen("start https://www.github.com", "r");
}

void Command::open_linkedin() {
    _popen("start https://www.linkedin.com", "r");
}

void Command::open_facebook() {
    _popen("start https://www.facebook.com", "r");
}

void Command::open_amazon() {
    _popen("start https://www.amazon.com", "r");
}

void Command::open_chatgpt() {
    _popen("start https://chatgpt.com", "r");
}


void Command::shutdown_pc() {
    ShellExecute(NULL, "open", "shutdown", "/s /f /t 0", NULL, SW_HIDE);
}
void Command::open_vscode() {
    ShellExecute(NULL, "open", "C:\\Users\\LAPTOP\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe", NULL, NULL, SW_SHOWNORMAL);
}
void Command::open_obs() {
    ShellExecute(NULL, "open", "C:\\Program Files\\obs-studio\\bin\\64bit\\obs64.exe", NULL, "C:\\Program Files\\obs-studio", SW_SHOWNORMAL);
}


void Command::open_visual_studio_2022() {
    ShellExecute(NULL, "open", "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Common7\\IDE\\devenv.exe", NULL, NULL, SW_SHOWNORMAL);
}

void Command::open_telegram() {
    ShellExecute(NULL, "open", "C:\\Users\\LAPTOP\\AppData\\Roaming\\Telegram Desktop\\Telegram.exe", NULL, NULL, SW_SHOWNORMAL);
}
void Command::open_whatsapp() {
    ShellExecute(NULL, "open", "whatsapp://", NULL, NULL, SW_SHOWNORMAL);
}


void Command::open_discord() {
    ShellExecute(NULL, "open", "C:\\Users\\LAPTOP\\AppData\\Local\\Discord\\app-1.0.9163\\Discord.exe", NULL, NULL, SW_SHOWNORMAL);
}

void Command::open_alarm() {
    ShellExecute(NULL, "open", "ms-clock://", NULL, NULL, SW_SHOWNORMAL);
}

void Command::open_chrome() {
    ShellExecute(NULL, "open", "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", NULL, NULL, SW_SHOWNORMAL);
}

void Command::open_edge() {
    ShellExecute(NULL, "open", "C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", NULL, NULL, SW_SHOWNORMAL);
}

void Command::open_pes19() {
    ShellExecute(NULL, "open", "D:\\Games\\pes19\\pes2019.exe", NULL, NULL, SW_SHOWNORMAL);
}

