import React from 'react';
import { NavLink } from 'react-router-dom';
import { Activity, Map, Radio, Sliders, FileText } from 'lucide-react';
import clsx from 'clsx';

const navigation = [
  { name: 'Status', icon: Activity, href: '/' },
  { name: 'Map View', icon: Map, href: '/map' },
  { name: 'Telemetry', icon: Radio, href: '/telemetry' },
  { name: 'Controls', icon: Sliders, href: '/controls' },
  { name: 'Logs', icon: FileText, href: '/logs' },
];

export default function Sidebar() {
  return (
    <nav className="w-64 bg-white border-r border-gray-200 min-h-[calc(100vh-4rem)]">
      <div className="p-4">
        <ul className="space-y-1">
          {navigation.map((item) => (
            <li key={item.name}>
              <NavLink
                to={item.href}
                className={({ isActive }) =>
                  clsx(
                    'flex items-center px-4 py-2 text-sm font-medium rounded-md',
                    isActive
                      ? 'bg-blue-50 text-blue-600'
                      : 'text-gray-600 hover:bg-gray-50 hover:text-gray-900'
                  )
                }
              >
                <item.icon className="mr-3 h-5 w-5" />
                {item.name}
              </NavLink>
            </li>
          ))}
        </ul>
      </div>
    </nav>
  );
}