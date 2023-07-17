#!/usr/bin/env powershell

Import-Module -Name PSDesiredStateConfiguration

Configuration NotepadInstallation {
    Node "localhost" {
        Package Notepad {
            Ensure = "Present"
            Name = "Notepad"
            Path = "C:\Users\leasu\Downloads\npp.8.5.4.Installer.x64"
	    ProductId = "NotepadProductId"   # Provide a unique identifier for Notepad
        }
    }
}


NotepadInstallation -OutputPath "C:\Users\leasu\Downloads"
Start-DscConfiguration -Path "C:\Users\leasu\Downloads" -Wait -Verbose

