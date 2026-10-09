using System;
using SaturnBuildTool;

public class DramBoxGame : GameDistTarget
{
    public override void Init()
    {
        base.Init();

        Name = "DramBoxGame";

        // When adding modules the name of the module has to match the file name but not the folder name...
        Modules.Add( "DramBox" );
    }
}
