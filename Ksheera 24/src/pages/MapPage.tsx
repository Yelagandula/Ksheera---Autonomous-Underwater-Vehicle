import React, { useEffect, useRef, useState } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';

mapboxgl.accessToken = 'pk.eyJ1IjoieWVsYWdhbmR1bGF2MSIsImEiOiJjbTlkdjliNnIwamZwMmlvYTltcDF2Nmg4In0.FLmcGlja_hWkxlkPp28XfA';

export default function MapPage() {
  const mapContainer = useRef<HTMLDivElement>(null);
  const map = useRef<mapboxgl.Map | null>(null);
  const marker = useRef<mapboxgl.Marker | null>(null);
  const [position, setPosition] = useState({
    lat: 37.7749,
    lng: -122.4194
  });

  useEffect(() => {
    if (!mapContainer.current) return;
    if (map.current) return;

    // Initialize map
    map.current = new mapboxgl.Map({
      container: mapContainer.current,
      style: 'mapbox://styles/mapbox/satellite-streets-v12',
      center: [position.lng, position.lat],
      zoom: 12,
    });

    // Add navigation controls
    map.current.addControl(new mapboxgl.NavigationControl(), 'top-right');

    // Add marker
    marker.current = new mapboxgl.Marker({
      color: '#ff0000',
      scale: 0.8,
    })
      .setLngLat([position.lng, position.lat])
      .addTo(map.current);

    // Cleanup
    return () => {
      map.current?.remove();
      map.current = null;
    };
  }, []);

  // Simulate AUV movement
  useEffect(() => {
    const interval = setInterval(() => {
      const newPosition = {
        lng: position.lng + (Math.random() - 0.5) * 0.01,
        lat: position.lat + (Math.random() - 0.5) * 0.01
      };
      
      setPosition(newPosition);
      marker.current?.setLngLat([newPosition.lng, newPosition.lat]);
      map.current?.easeTo({
        center: [newPosition.lng, newPosition.lat],
        duration: 1000
      });
    }, 2000);

    return () => clearInterval(interval);
  }, [position]);

  return (
    <div className="p-6">
      <h1 className="text-2xl font-bold mb-4">Map View</h1>
      <div className="bg-white rounded-lg shadow-lg overflow-hidden">
        <div ref={mapContainer} className="w-full h-[600px]" />
        <div className="p-4 bg-gray-50 border-t">
          <p className="text-sm text-gray-600">
            Current Position: {position.lat.toFixed(4)}°N, {position.lng.toFixed(4)}°W
          </p>
        </div>
      </div>
    </div>
  );
}