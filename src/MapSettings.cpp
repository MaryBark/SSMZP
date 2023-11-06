#include "inc/MapSettings.h"
#include "ui_MapSettings.h"

MapSettings::MapSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapSettings)
{
    ui->setupUi(this);
    setWindowTitle("Настройки карты");
}

MapSettings::~MapSettings()
{
    delete ui;
}

bool MapSettings::showAtmosphere() const
{ return ui->cbShowAtmosphere->isChecked();}

void MapSettings::setShowAtmosphere(const bool showAtmosphere)
{   ui->cbShowAtmosphere->setChecked(showAtmosphere);   }

bool MapSettings::showBorders() const
{   return ui->cbShowBorders->isChecked();  }

void MapSettings::setShowBorders(const bool showBorders)
{   ui->cbShowBorders->setChecked(showBorders); }

bool MapSettings::showCities() const
{   return ui->cbShowCities->isChecked();   }

void MapSettings::setShowCities(const bool showCities)
{   ui->cbShowCities->setChecked(showCities);   }

bool MapSettings::showCityLights() const
{   return ui->cbShowCityLights->isChecked();   }

void MapSettings::setShowCityLights(const bool showCityLights)
{   ui->cbShowCityLights->setChecked(showCityLights);   }

bool MapSettings::showClouds() const
{   return ui->cbShowClowds->isChecked();   }

void MapSettings::setShowClouds(const bool showClouds)
{   ui->cbShowClowds->setChecked(showClouds);   }

bool MapSettings::showCompass() const
{   return ui->cbShowCompass->isChecked();  }

void MapSettings::setShowCompass(const bool showCompass)
{   ui->cbShowCompass->setChecked(showCompass); }

bool MapSettings::showCrosshairs() const
{   return ui->cbShowCrosshairs->isChecked();   }

void MapSettings::setShowCrosshairs(const bool showCrosshairs)
{   ui->cbShowCrosshairs->setChecked(showCrosshairs);   }

bool MapSettings::showGrid() const
{   return ui->cbShowGrid->isChecked(); }

void MapSettings::setShowGrid(const bool showGrid)
{   ui->cbShowGrid->setChecked(showGrid);   }

bool MapSettings::showIceLayer() const
{   return ui->cbShowIceLayer->isChecked(); }

void MapSettings::setShowIceLayer(const bool showIceLayer)
{   ui->cbShowIceLayer->setChecked(showIceLayer);   }

bool MapSettings::showLakes() const
{   return ui->cbShowLakes->isChecked();    }

void MapSettings::setShowLakes(const bool showLakes)
{   ui->cbShowLakes->setChecked(showLakes); }

bool MapSettings::showOtherPlaces() const
{   return ui->cbShowOthePlaces->isChecked();   }

void MapSettings::setShowOtherPlaces(const bool showOtherPlaces)
{   ui->cbShowOthePlaces->setChecked(showOtherPlaces);  }

bool MapSettings::showOverviewMap() const
{   return ui->cbShowOverviewMap->isChecked();  }

void MapSettings::setShowOverviewMap(const bool showOverviewMap)
{   ui->cbShowOverviewMap->setChecked(showOverviewMap); }

bool MapSettings::showPlaces() const
{   return ui->cbShowPlaces->isChecked();   }

void MapSettings::setShowPlaces(const bool showPlaces)
{   ui->cbShowPlaces->setChecked(showPlaces);   }

bool MapSettings::showRelief() const
{   return ui->cbShowRelief->isChecked();   }

void MapSettings::setShowRelief(const bool showRelief)
{   ui->cbShowRelief->setChecked(showRelief);   }

bool MapSettings::showRivers() const
{   return ui->cbShowRivers->isChecked();   }

void MapSettings::setShowRivers(const bool showRivers)
{   ui->cbShowRivers->setChecked(showRivers);   }

bool MapSettings::showScaleBar() const
{   return ui->cbShowScaleBar->isChecked(); }

void MapSettings::setShowScaleBar(const bool showScaleBar)
{   ui->cbShowScaleBar->setChecked(showScaleBar);   }

bool MapSettings::showSunShading() const
{   return ui->cbShowSunShading->isChecked();   }

void MapSettings::setShowSunShading(const bool showSunShading)
{   ui->cbShowSunShading->setChecked(showSunShading);   }

bool MapSettings::showTerrain() const
{   return ui->cbShowTerrain->isChecked();  }

void MapSettings::setShowTerrain(const bool showTerrain)
{   ui->cbShowTerrain->setChecked(showTerrain); }

bool MapSettings::showSubSolarPointIcon() const
{   return ui->cbShowSubSolarPointIcon->isChecked();    }

void MapSettings::setShowSubSolarPointIcon(
        const bool showSubSolarPointIcon)
{   ui->cbShowSubSolarPointIcon->setChecked(showSubSolarPointIcon); }

bool MapSettings::showBackGround() const
{   return ui->cbShowBackground->isChecked();   }

void MapSettings::setShowBackGround(const bool showBackGround)
{   ui->cbShowBackground->setChecked(showBackGround);   }

bool MapSettings::showNavigationPanel() const
{   return ui->cbShowNavigationPanel->isChecked();  }

void MapSettings::setShowNavigationPanel(const bool showNavigationPanel)
{   ui->cbShowNavigationPanel->setChecked(showNavigationPanel); }

//QPen MapSettings::trackPen() const
//{   return ui->wTrackPen->value();  }

//void MapSettings::setTrackPen(const QPen & pen)
//{   ui->wTrackPen->setValue(pen);   }
