import './style.css';
import { Map, View } from 'ol';
import { fromLonLat } from 'ol/proj';
import TileLayer from 'ol/layer/Tile';
import OSM from 'ol/source/OSM';
import VectorLayer from 'ol/layer/Vector';
import VectorSource from 'ol/source/Vector';
import Feature from 'ol/Feature';
import Point from 'ol/geom/Point';
import { Icon, Style } from 'ol/style';

const centerCoordinates = fromLonLat([9.76727, 50.67966]);

// Create a marker feature at the center position
const marker = new Feature({
  geometry: new Point(centerCoordinates)
});

// Style the marker using an icon image (ensure marker.png is in your project)
marker.setStyle(
  new Style({
    image: new Icon({
      anchor: [0.5, 1],
      src: "./images/marker.png" // Replace with the path to your marker image
    })
  })
);

// Create a vector source and layer to hold the marker
const vectorSource = new VectorSource({
  features: [marker]
});

const markerLayer = new VectorLayer({
  source: vectorSource
});

// Create the map with the OSM base layer and the marker layer, centering the view at the marker
const map = new Map({
  target: 'map',
  layers: [
    new TileLayer({
      source: new OSM()
    }),
    markerLayer
  ],
  view: new View({
    center: centerCoordinates,
    zoom: 15
  })
});


/*
Editing marker position
const newLonLat = [10.0, 51.0];

// Convert new coordinates to the map's projection (EPSG:3857 by default)
const newCoordinates = fromLonLat(newLonLat);

// Update the marker's geometry to the new position
marker.setGeometry(new Point(newCoordinates));
*/