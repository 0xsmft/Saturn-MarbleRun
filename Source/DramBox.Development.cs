using System;
using SaturnBuildTool;

public class DramBoxEditor : GameDevelopmentTarget
{
    public override void Init()
    {
        base.Init();

        Name = "DramBox";

        // When adding modules the name of the module has to match the file name but not the folder name...
        Modules.Add( "DramBox" );
        // Include directories relative to root folder (solution directory)
    
        Includes.Add( "DramBox/Source/DramBox" );
    }
}
