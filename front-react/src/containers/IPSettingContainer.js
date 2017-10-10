import React, {Component} from 'react';

import {IPSetting, IPSettingAside} from '../components';

export default class IPSettingContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <IPSetting />
                <IPSettingAside />
            </div>
        );
    }
}
