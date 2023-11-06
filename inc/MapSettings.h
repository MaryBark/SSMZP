#ifndef MAPSETTINGS_H
#define MAPSETTINGS_H

#include <QWidget>
#include <QPen>
//#include "ssrc/MapSettings.ui"

namespace Ui {
class MapSettings;
}

class MapSettings : public QWidget
{
    Q_OBJECT

public:
    explicit MapSettings(QWidget *parent = nullptr);
    ~MapSettings();

    bool showAtmosphere() const;
    void setShowAtmosphere(const bool);

    bool showBorders() const;
    void setShowBorders(const bool);

    bool showCities() const;
    void setShowCities(const bool);

    bool showCityLights() const;
    void setShowCityLights(const bool);

    bool showClouds() const;
    void setShowClouds(const bool);

    bool showCompass() const;
    void setShowCompass(const bool);

    bool showCrosshairs() const;
    void setShowCrosshairs(const bool);

    bool showGrid() const;
    void setShowGrid(const bool);

    bool showIceLayer() const;
    void setShowIceLayer(const bool);

    bool showLakes() const;
    void setShowLakes(const bool);

    bool showOtherPlaces() const;
    void setShowOtherPlaces(const bool);

    bool showOverviewMap() const;
    void setShowOverviewMap(const bool);

    bool showPlaces() const;
    void setShowPlaces(const bool);

    bool showRelief() const;
    void setShowRelief(const bool);

    bool showRivers() const;
    void setShowRivers(const bool);

    bool showScaleBar() const;
    void setShowScaleBar(const bool);

    bool showSunShading() const;
    void setShowSunShading(const bool);

    bool showTerrain() const;
    void setShowTerrain(const bool);

    bool showSubSolarPointIcon() const;
    void setShowSubSolarPointIcon(const bool);

    bool showBackGround() const;
    void setShowBackGround(const bool);

    bool showNavigationPanel() const;
    void setShowNavigationPanel(const bool);

    QPen trackPen() const;
    void setTrackPen(const QPen&);


public Q_SLOTS:


private:
    Ui::MapSettings *ui;
};

#endif // MAPSETTINGS_H
