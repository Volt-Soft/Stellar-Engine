import ldtk.LDtkProject;
import ldtk.LDtkLevel;
import ldtk.Tile;
import openfl.Assets;
import openfl.display.Sprite;
import openfl.display.BitmapData;
import openfl.display.Tilemap;
import openfl.display.Tileset;
import openfl.geom.Rectangle;

class Main extends Sprite {

    public function new() {
        super();
        loadLevel();
    }

    function loadLevel():Void {
        // Load LDtk project JSON
        var ldtkData:String = Assets.getText("assets/level.ldtk");
        var project:LDtkProject = new LDtkProject(ldtkData);
        
        // Access the first level
        var level:LDtkLevel = project.getLevel("Level 1"); // Replace "Level 1" with your level's actual name
        
        // Load tileset image
        var tilesetImage:BitmapData = Assets.getBitmapData("assets/tileset.png"); // Example tileset
        
        // Set up tilemap for rendering
        var tilemap:Tilemap = new Tilemap(stage.stageWidth, stage.stageHeight);
        var tileSize:Int = 32; // Set according to your tile size
        
        var tileset:Tileset = new Tileset(tilesetImage, [new Rectangle(0, 0, tileSize, tileSize)]);
        tilemap.addTileset(tileset);
        addChild(tilemap);
        
        // Loop through layers and place tiles
        for (layer in level.layers) {
            if (layer.isTiles) {
                for (tile in layer.gridTiles) {
                    var x:Int = tile.x / tileSize;
                    var y:Int = tile.y / tileSize;
                    var tileID:Int = tile.tilesetX / tileSize;
                    tilemap.setTile(x, y, tileID);
                }
            }
        }
    }
}

