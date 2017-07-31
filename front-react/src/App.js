import React, { Component } from 'react';

import {Nav} from './components';
import {NetworkInfo, NetworkInfoSide} from './components';
import {AdminInfo, AdminInfoSide} from './components';

import {ChangeModeButton} from './components';

import {Footer} from './components';


class App extends Component {
  render() {
    return (
        <div className='container'>
            <div className='wrapper'>
                <Nav />
                <div className='row'>
                    <AdminInfo />
                    <AdminInfoSide />
                    <ChangeModeButton />
                </div>
                <Footer />
            </div>
        </div>
    );
  }
}

export default App;
