PuTTY Portable Launcher 1.3.6.0
===============================
Copyright 2004-2007 John T. Haller

Website: http://PortableApps.com/PuTTYPortable

This software is OSI Certified Open Source Software.
OSI Certified is a certification mark of the Open Source Initiative.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.


ABOUT PUTTY PORTABLE
====================
The PuTTY Portable Launcher allows you to run PuTTY from a removable drive whose letter changes as you move it to another computer.  The program can be entirely self-contained on the drive and then used on any Windows computer.


LICENSE
=======
This code is released under the GPL.  The full code is included with this package as PuTTYPortable.nsi.


INSTALLATION / DIRECTORY STRUCTURE
==================================
By default, the program expects one of these directory structures:

-\ <--- Directory with PuTTYPortable.exe
	+\App\
		+\putty\
	+\Data\
		+\settings\

OR

-\ <--- Directory with PuTTYPortable.exe
	+\PuTTYPortable\
		+\App\
			+\putty\
		+\Data\
			+\settings\

It can be used in other directory configurations by including the PuTTYPortable.ini file in the same directory as PuTTYPortable.exe and configuring it as details in the INI file section below.


PUTTYPORTABLE.INI CONFIGURATION
===============================
The PuTTY Portable Launcher will look for an ini file called PuTTYPortable.ini (read the previous section for details on placement).  If you are happy with the default options, it is not necessary, though.  The INI file is formatted as follows:

[PuTTYPortable]
PuTTYDirectory=App\putty
SettingsDirectory=Data\settings
PuTTYExecutable=putty.exe
AdditionalParameters=
DisableSplashScreen=false

The PuTTYDirectory and SettingsDirectory entries should be set to the *relative* path to the appropriate directories from the current directory.  All must be a subdirectory (or multiple subdirectories) of the directory containing PuTTYPortable.exe.  The default entries for these are described in the installation section above.

The PuTTYExecutable entry allows you to set the Miranda Portable Launcher to use an alternate EXE call to launch PuTTY.  This is helpful if you are using a machine that is set to deny putty.exe from running.  You'll need to rename the putty.exe file and then enter the name you gave it on the PuTTYExecutable= line of the INI.

The AdditionalParameters entry allows you to pass additional commandline parameter entries to putty.exe.  Whatever you enter here will be appended to the call to putty.exe.

The DisableSplashScreen entry allows you to run the PuTTY Portable Launcher without the splash screen showing up.  The default is false.