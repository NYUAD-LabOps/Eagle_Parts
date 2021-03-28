Using Notepad++ for Eagle ULP Development

Notepad++ is a free (as in "free speech" and also as in "free beer") source code editor and Notepad replacement that supports several languages.  Running in the MS Windows environment, its use is governed by GPL License.  Obtain it from http://notepad-plus-plus.org/

Notepad++ has a User Defined Language facility that is documented in its help files and at the NpWiki++:
http://sourceforge.net/apps/mediawiki/notepad-plus/index.php?title=User_Defined_Languages

The file "Notepad++ UserDefineLang for Cadsoft ULP v0.1.xml" contains a beta release of a Notepad++ user defined language corresponding to ULP for Cadsoft Eagle v5.  This language defintion may not always correctly display ULP keywords, for example, owing to white space or your variable names.  I found it helpful for developing ULPs, YMMV.  THIS LANGUAGE DEFINITION IS PROVIDED AS IS AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED OR IMPLIED.

To use this langauge definition in Notepad++ click View | User-Defined Dialog | Import and select the XML file.  Now when editing a file with extension .ULP the Eagle ULP keywords should be formatted according to the styles in the User-Defined dialog.

In order to have Notepad++ automatically open the ULP file and position the cursor on the line of an error in a ULP, you need Eagle V5.5 or later.  Set the Eagle Options | User Interface | External Text Editor field to (include the quotation marks and edit the Notepad++.exe location to suit your installation):
"C:\Program Files\Notepad++\Notepad++.exe" -n%L "%F" 
Please refer to "Help | Editor Windows | Text Editor" in the Eagle help files for more information.  

Neil Allison
www.avon-tech-solutions.co.nz
16-Aug-2010

UPDATE 06-23-2013:
New functions are included in V0.2.
Jorge Garcia
Cadsoft Computer