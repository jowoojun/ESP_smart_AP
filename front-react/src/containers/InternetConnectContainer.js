import React, {Component} from 'react';

import {InternetConnect, InternetConnectSide} from '../components';
import {ChangeModeButtonAdvance} from '../components';


class InternetConnectContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <InternetConnect />
                <InternetConnectSide />
                <ChangeModeButtonAdvance />
            </div>
        );
    }
}

export default InternetConnectContainer;
