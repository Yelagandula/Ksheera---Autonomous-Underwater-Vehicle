import React from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Layout from './components/Layout';
import StatusPage from './pages/StatusPage';
import MapPage from './pages/MapPage';
import TelemetryPage from './pages/TelemetryPage';
import ControlsPage from './pages/ControlsPage';
import LogsPage from './pages/LogsPage';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Layout />}>
          <Route index element={<StatusPage />} />
          <Route path="map" element={<MapPage />} />
          <Route path="telemetry" element={<TelemetryPage />} />
          <Route path="controls" element={<ControlsPage />} />
          <Route path="logs" element={<LogsPage />} />
        </Route>
      </Routes>
    </BrowserRouter>
  );
}

export default App;