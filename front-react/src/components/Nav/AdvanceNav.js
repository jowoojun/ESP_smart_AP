import React, {PureComponent} from 'react';
import {Link} from 'react-router'
import Footer from '../Footer';

class AdvanceNav extends PureComponent{

    active(path){

        if(this.props.pathname === path){
            return 'active'
        }
    }


    render(){

        return(
            <div className='container'>
                <div className='wrapper'>
                    <div>
                        <div className="navbar-header">
                            <a className="navbar-brand" href="/">관리</a>
                        </div>
                        <div className="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                            <ul className="nav navbar-nav tab">
                                <li className="current" data-tab="internet_info">
                                    <Link to='/advance' className={this.active('/advance')}>차단 페이지</Link>
                                </li>
                                <li data-tab="admin_setting">
                                    <Link to ='/advance/reservation' className={this.active('/advance/reservation')}>예약 차단</Link>
                                </li>
                            </ul>
                        </div>
                    </div>
                    <div className='row'>
                        {this.props.children}
                    </div>
                    <Footer />
                </div>
            </div>
        );
    }
}


export default AdvanceNav;
