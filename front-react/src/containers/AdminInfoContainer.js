import React, {Component} from 'react';

import {AdminInfo, AdminInfoSide} from '../components';
import {ChangeModeButton} from '../components';


class AdminInfoContainer extends Component{

    render(){

        return(
            <div>
                <AdminInfo />
                <AdminInfoSide />
                <ChangeModeButton />
            </div>
        );
    }
}

export default AdminInfoContainer
